#include "getshellwin.h"

#ifndef MKBADDR
#define MKBADDR(p) (((ULONG)(p))) >> 2)
#endif

LONG send_packet(
	struct MsgPort *port,
	LONG action,
	int num_args,
	LONG *args
) {
	struct Process *process = (struct Process *)FindTask(NULL);
	struct MsgPort *replyPort = &process->pr_MsgPort;
	struct StandardPacket *packet;
	unsigned long requirements = MEMF_PUBLIC | MEMF_CLEAR;
	LONG result;
	
	packet = (struct StandardPacket *)AllocMem(sizeof(*packet), requirements);
	if (packet != NULL) {
		LONG *packetArgs = &packet->sp_Pkt.dp_Arg1;
		int i;
		
		packet->sp_Msg.mn_Node.ln_Name = (char *)&packet->sp_Pkt;
		packet->sp_Pkt.dp_Link = &packet->sp_Msg;
		packet->sp_Pkt.dp_Port = replyPort;
		packet->sp_Pkt.dp_Type = action;
		
		if (num_args > 7)
		  num_args = 7;
		  
		for (i = 0; i < num_args; i++)
		  packetArgs[i] = args[i];
		  
		PutMsg(port, (struct Message *)packet);
		
		WaitPort(replyPort);
		GetMsg(replyPort);
		
		result = packet->sp_Pkt.dp_Res1;
		
		FreeMem(packet, sizeof(*packet));
  }
  else {
    result = DOSFALSE;
  }
  
  return result;
}

struct Window *GetShellWindow(void) {
  GSHContext context = GetShellWindowContext();
  return context.window;
}

GSHContext GetShellWindowContext(void) {
  GSHContext context;
	unsigned long requirements = MEMF_PUBLIC | MEMF_CLEAR;
	struct Process *process = (struct Process *)FindTask(NULL);
	struct InfoData *id;

  context.window = NULL;
	context.ior = NULL;
	context.conUnit = NULL;
	
	if (process->pr_ConsoleTask != NULL)
	{
		id = (struct InfoData *)AllocMem(sizeof(*id), requirements);
		if (id != NULL) 
		{
			LONG args[1];
			
			args[0] = MKBADDR(id);
			
			if (send_packet(process->pr_ConsoleTask, ACTION_DISK_INFO, 1, args)) 
			{				
				context.window = (struct Window *)id->id_VolumeNode;
				context.ior = (struct IORequest *)id->id_InUse;
				context.conUnit = (context.ior != NULL) 
				  ? (struct ConUnit *)context.ior->io_Unit 
				  : NULL;								
			}
			
			FreeMem(id, sizeof(*id));
		}
	}
	
	return context;
}