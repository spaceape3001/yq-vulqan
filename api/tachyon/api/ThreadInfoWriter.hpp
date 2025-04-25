////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Thread.hpp>
#include <tachyon/api/ThreadData.hpp>
#include <tachyon/api/TachyonInfoWriter.hpp>

namespace yq::tachyon {
    /*! \brief Writer of manager information
    */
    template <typename C>
    class ThreadInfo::Writer : public TachyonInfo::Writer<C> {
    public:
    
        //! Constructor of widget info (this is used by derived classes and this classes other constructor)
        Writer(ThreadInfo* theInfo) : TachyonInfo::Writer<C>(theInfo), m_meta(theInfo)
        {
        }
        
        //! Constructor of widget info (this is used by the writer<T>() methods)
        Writer(ThreadInfo& theInfo) : Writer(&theInfo)
        {
        }

    private:
        ThreadInfo* m_meta;
    };
}
