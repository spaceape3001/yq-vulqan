////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Thread.hpp>
#include <yq/tachyon/thread/EditThread.hpp>
#include <yq/vkqt/XThread.hpp>

using namespace yq;
using namespace yq::tachyon;

// want one of these PER document...
class SCEDoc : public XThread<EditThread> {
    YQ_TACHYON_DECLARE(SCEDoc, EditThread)
    Q_OBJECT
public:

    static void init_meta();
    
    SCEDoc();
    ~SCEDoc();
};
