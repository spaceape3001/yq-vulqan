////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once
#include <yq/container/Map.hpp>
#include <yq/tachyon/api/Manager.hpp>
#include <yq/vkqt/XTachyon.hpp>

namespace yq::tachyon {

    class MTachyon;

    //! To manage everything, available in the main thread
    class TEManager : public XTachyon<QObject, Manager> {
        YQ_TACHYON_DECLARE(TEManager, Manager)
        Q_OBJECT
    public:
    
        static TEManager*   instance() { return s_instance; }
    
        TEManager();
        ~TEManager();
        
        MTachyon*     manage(TypedID);
        
        
        static void init_meta();
    private:
        static thread_local TEManager*  s_instance;
        
        Map<uint64_t,MTachyon*>    m_managed;
    };
}
