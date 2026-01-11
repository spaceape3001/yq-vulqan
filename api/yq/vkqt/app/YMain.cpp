////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "YMain.hpp"
#include "YMainMetaWriter.hpp"
#include "YAppThread.hpp"
#include <yq/tachyon/thread/AppThread.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::YMain)

namespace yq::tachyon {
    YMain::YMain()
    {
    }
    
    YMain::~YMain()
    {
    }
        
    void YMain::closing() 
    {
        cmd_teardown();
    }

    Execution    YMain::setup(const Context&ctx) 
    {
        if(!m_counted){
            if(YAppThread* yt = dynamic_cast<YAppThread*>(Thread::current())){
                yt -> add(*this);
                m_counted   = true;
            }
            return WAIT;
        }
    
        return Tachyon::setup(ctx);
    }
    
    Execution    YMain::teardown(const Context&ctx) 
    {   
        //  nothing here... (for now)
        return Tachyon::teardown(ctx);
    }

    void YMain::init_meta()
    {
        auto w = writer<YMain>();
        w.description("Tachyon's Qt Main Window (Abstract)");
        w.abstract();
    }
}


#include "moc_YMain.cpp"
