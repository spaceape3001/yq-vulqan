////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/utility/LoggerBox.hpp>
#include <yq/core/StreamOps.hpp>
#include <yq/stream/Logger.hpp>
#include <log4cpp/Category.hh>
#include <log4cpp/CategoryStream.hh>
#include <tachyon/api/TachyonMetaWriter.hpp>
#include <tachyon/command/tachyon/SnoopCommand.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::LoggerBox)

namespace yq::tachyon {
    LoggerBox::LoggerBox() : LoggerBox(Param()) {}
    LoggerBox::LoggerBox(const Param& cfg) : 
        m_category(log_category(cfg.category)), m_priority(log4cpp_priority(cfg.priority))
    {
    }
        
    LoggerBox::~LoggerBox()
    {
    }

    void LoggerBox::dispatch(const PostCPtr& pp)
    {
        if(!pp)
            return ;
        
        const auto&     pi  = pp->metaInfo();
        stream::Logger  log(m_category.getStream(m_priority));
        log << pi.stem() << "[" << pp->id() << "]";
        bool    f = true;
        
        for(const PropertyInfo* prop : pi.properties(ALL).all){
            // filter out properties
            if(prop->name() == "id")
                continue;
            if(!prop->tagged(Post::kTag_Log))
                continue;

            // Comma!
            if(f){  
                log << " ";
                f = false;
            } else {
                log << "; ";
            }
        
            log << prop->name() << "=\"";
            prop->print(pp.ptr(), log);
            log << "\"";
        }
    }

    void    LoggerBox::unsafe_snoop(Tachyon* tac)
    {
        tac->mail(new SnoopCommand({.target=tac}, *this));
    }
    
}
