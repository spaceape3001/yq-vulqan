////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Tachyon.hpp"
#include "TachyonInfoWriter.hpp"
#include <yq/core/ThreadId.hpp>

namespace yq::tachyon {

    TachyonInfo::TachyonInfo(std::string_view zName, post::PBXInfo& base, const std::source_location& sl) :
        post::PBXInfo(zName, base, sl)
    {
        set(Flag::TACHYON);
    }

    Tachyon::Tachyon(const Param& p) : Tachyon(p, INIT)
    {
        //  Add to thread...
    }
    
    Tachyon::Tachyon(const Param&p, init_t) : post::PBX(p)
    {
        m_threadId  = thread::id();
    }

    Tachyon::Tachyon(const Param& p, thread_t) : Tachyon(p, INIT)
    {
    }

    Tachyon::~Tachyon()
    {
    }
    
    bool Tachyon::in_thread() const
    {
        return m_threadId == thread::id();
    }

    void Tachyon::init_info()
    {
        auto w = writer<Tachyon>();
        w.description("Tachyon abstract base class");
    }

}

YQ_OBJECT_IMPLEMENT(yq::tachyon::Tachyon)
