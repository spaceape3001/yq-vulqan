////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/post/PBXInfoWriter.hpp>
#include <yq/tachyon/core/Thread.hpp>

namespace yq::tachyon {
    /*! \brief Writer of manager information
    */
    template <typename C>
    class ThreadInfo::Writer : public PBXInfo::Writer<C> {
    public:
    
        //! Constructor of widget info (this is used by derived classes and this classes other constructor)
        Writer(ThreadInfo* theInfo) : PBXInfo::Writer<C>(theInfo), m_meta(theInfo)
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
