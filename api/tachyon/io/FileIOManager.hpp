////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Manager.hpp>

namespace yq::tachyon {
    class LoadTSXRequest;
    class SaveTSXRequest;
    class SaveReply;
    
    class FileIOManager : public Manager {
        YQ_TACHYON_DECLARE(FileIOManager, Manager)
    public:
        static void init_info();
    
        FileIOManager();
        virtual ~FileIOManager();
        
    protected:
        //  TODO
        
        void on_load_tsx_request(const Ref<const LoadTSXRequest>&);
        void on_save_tsx_request(const Ref<const SaveTSXRequest>&);
        
        void on_save_reply(const Ref<const SaveReply>&);
    };
}
