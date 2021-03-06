/* Header for OpCode class
   Copyright (C) 2018-2019 Adam Leszczynski.

This file is part of Open Log Replicator.

Open Log Replicator is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License as published
by the Free Software Foundation; either version 3, or (at your option)
any later version.

Open Log Replicator is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
Public License for more details.

You should have received a copy of the GNU General Public License
along with Open Log Replicator; see the file LICENSE.txt  If not see
<http://www.gnu.org/licenses/>.  */

#include <string>
#include "types.h"

#ifndef OPCODE_H_
#define OPCODE_H_

using namespace std;

namespace OpenLogReplicatorOracle {

	class OracleEnvironment;
	class RedoLogRecord;

	class OpCode {
	protected:
		OracleEnvironment *oracleEnvironment;
		RedoLogRecord *redoLogRecord;

		void ktbRedo(uint32_t fieldPos, uint32_t fieldLength);
		void kdoOpCode(uint32_t fieldPos, uint32_t fieldLength);
		void ktub(uint32_t fieldPos, uint32_t fieldLength);
		void ktubu(uint32_t fieldPos, uint32_t fieldLength);
		virtual const char* getUndoType();
		virtual bool isKdoUndo();

	public:
		uint8_t itli;
	    uint8_t slot;

		virtual void process();
		virtual string getName();
		virtual void dumpDetails();
		void dump();
		virtual uint16_t getOpCode(void);
		void appendValue(uint32_t typeNo, uint32_t fieldPosTmp, uint32_t fieldLength);

		OpCode(OracleEnvironment *oracleEnvironment, RedoLogRecord *redoLogRecord);
		OpCode(OracleEnvironment *oracleEnvironment, RedoLogRecord *redoLogRecord, bool fill);
		virtual ~OpCode();
	};
}

#endif
