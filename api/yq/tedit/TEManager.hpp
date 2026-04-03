////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once
#include <yq/tachyon/api/Manager.hpp>
#include <yq/vkqt/XTachyon.hpp>

namespace yq::tachyon {

    //! To manage everything, available in the main thread
    class TEManager : public XTachyon<QObject, Manager> {
        YQ_TACHYON_DECLARE(TEManager, Manager)
        Q_OBJECT
    public:
    
        static TEManager*   instance() { return s_instance; }
    
        TEManager();
        ~TEManager();
        
        static void init_meta();
    private:
        static thread_local TEManager*  s_instance;
    };
}
