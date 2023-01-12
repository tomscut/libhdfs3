/********************************************************************
 * 2023 -
 * open source under Apache License Version 2.0
 ********************************************************************/
/**
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _HDFS_LIBHDFS3_ECCHUNK_H_
#define _HDFS_LIBHDFS3_ECCHUNK_H_

#include "ByteBuffer.h"

#include <vector>
#include <memory>

namespace Hdfs {
namespace Internal {

class ECChunk {
private:
    std::shared_ptr<ByteBuffer> chunkBuffer;
    bool allZero = false;

public:
    ECChunk();
    ECChunk(std::vector<int8_t> buffer);
    ECChunk(std::vector<int8_t> buffer, int offset, int len);
    ECChunk(std::shared_ptr<ByteBuffer> buffer);
    ECChunk(std::shared_ptr<ByteBuffer> buffer, int offset, int len);
    ~ECChunk();
    
    bool isAllZero();
    void setAllZero(bool allZero);
    std::shared_ptr<ByteBuffer> getBuffer();
    std::vector<int8_t> toBytesArray();
};

}
}


#endif /* _HDFS_LIBHDFS3_ECCHUNK_H_ */