////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Logging.hpp>
#include <tachyon/api/Tachyon.hpp>

namespace yq::tachyon {
    /*! \brief Logs posts to the logger
    
        This logs received posts to the logger using the specified category/priority.
    */
    class LoggerBox : public Tachyon {
        YQ_TACHYON_DECLARE(LoggerBox, Tachyon)
    public:
       struct Param {
            const char*     category    = "post";
            LogPriority     priority    = kLogDef_File;
            bool            global      = false;
        };
    
        LoggerBox();
        LoggerBox(const Param& p);
        ~LoggerBox();
        
        //! NOT THREAD_SAFE
        void    unsafe_snoop(Tachyon*);
 
    private:
        log4cpp::Category&  m_category;
        int                 m_priority;
        virtual void dispatch(const PostCPtr&) override;
    };
}
