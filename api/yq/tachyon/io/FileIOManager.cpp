////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "FileIOManager.hpp"

#include <yq/core/Any.hpp>

#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/api/ID.hpp>
#include <yq/tachyon/api/ManagerMetaWriter.hpp>
#include <yq/tachyon/api/Thread.hpp>
#include <yq/tachyon/io/Save.hpp>
//#include <yq/tachyon/io/SaveXML.hpp>
#include <yq/tachyon/reply/io/LoadTSXReply.hpp>
#include <yq/tachyon/reply/io/SaveReply.hpp>
#include <yq/tachyon/reply/io/SaveTSXReply.hpp>
#include <yq/tachyon/request/io/LoadTSXRequest.hpp>
#include <yq/tachyon/request/io/SaveTSXRequest.hpp>
#include <yq/tachyon/request/io/SaveRequest.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::FileIOManager)

namespace yq::tachyon {
    void FileIOManager::init_meta()
    {
        auto    w   = writer<FileIOManager>();
        w.description("Manager of file I/O");
        w.slot(&FileIOManager::on_load_tsx_request);
        w.slot(&FileIOManager::on_save_reply);
        w.slot(&FileIOManager::on_save_tsx_request);
    }
    
    FileIOManager::FileIOManager()
    {
    }
    
    FileIOManager::~FileIOManager()
    {
    }

    void FileIOManager::on_load_tsx_request(const Ref<const LoadTSXRequest>&req)
    {
        if(!req)
            return ;
        if(req->filepath().empty()){
            tachyonWarning << "FileIOManager: LoadTSXRequest had an empty filepath, rejecting";
            send(new LoadTSXReply({.source=*this, .target=req->source()}, req, Response::InvalidArg));
            return;
        }
        
        SaveCPtr    sxml    = Save::IO::load(req->filepath(), { .cache=Tristate::No, .load=Tristate::Yes });
        if(!sxml){
            tachyonWarning << "FileIOManager: Unable to load file: " << req->filepath();
            send(new LoadTSXReply({.source=*this, .target=req->source()}, req, Response::IOError));
            return ;
        }
        
        tachyonAlert << "FileIOManager: LoadTSXRequest is currently non-operational";
        send(new LoadTSXReply({.source=*this, .target=req->source()}, req, Response::Failure));
        
        

    #if 0
        ReincarnationConfig config;
        config.owner    = req->thread();
        
        if(req->prep())
            req->prep()();
        
        TachyonIDSet        tachs;
        ec = sxml.save -> execute(SCHEDULE, config, &tachs);
        if(ec != std::error_code()){
            tachyonWarning << "FileIOManager: Unable to schedule tsx file (" << req->filepath() << ") due to: " << ec.message();
            send(new LoadTSXReply({.source=*this, .target=req->source()}, req, Response::Failure));
            return ;
        }
        
        send(new LoadTSXReply({.source=*this, .target=req->source()}, req, std::move(tachs)));
    #endif
    }

    void FileIOManager::on_save_reply(const Ref<const SaveReply>&rep)
    {
        if(!rep)
            return ;
            
        const SaveRequest*  cmd = dynamic_cast<const SaveRequest*>(rep->request());
        if(!cmd){
            tachyonWarning << "FileIOManager: SaveReply without a SaveRequest, rejecting";
            return ;
        }
        
        const SaveTSXRequest* req   = dynamic_cast<const SaveTSXRequest*>(cmd->cause());
        if(!req){
            tachyonWarning << "FileIOManager: SaveReply without a SaveTSXRequest, rejecting";
            return ;
        }
        
        if(!rep->save()){
            send(new SaveTSXReply({ .source=*this, .target=req->source() }, req, Response::Failure));
            return ;
        }
        
        SaveCPtr    sxml    = rep->save();
        std::error_code ec  = sxml->save_to(req->filepath(), { .collision=FileCollisionStrategy::Backup });
        if(ec != std::error_code()){
            tachyonWarning << "FileIOManager: Unable to save tsx file (" << req->filepath() << ") due to: " << ec.message();
            send(new SaveTSXReply({ .source=*this, .target=req->source()}, req, Response::IOError));
            return ;
        }
        
        tachyonNotice << "FileIOManager: Successfully saved to " << req->filepath();
        send(new SaveTSXReply({.source=*this, .target=req->source()}, req, Response::QaPla));
    }
    
    void FileIOManager::on_save_tsx_request(const Ref<const SaveTSXRequest>&req)
    {
        if(!req)
            return ;
        if(req->filepath().empty()){
            tachyonWarning << "FileIOManager: SaveTSXRequest had an empty filepath, rejecting";
            send(new SaveTSXReply({.source=*this, .target=req->source()}, req, Response::InvalidArg));
            return;
        }

        if(auto p = std::get_if<ThreadID>(&req->thread())){
            TypedID     tid(p->id, Type::Thread);
            send(new SaveRequest({.cause=req, .source=*this, .target=tid}, req->tachyons(), req->flags()));
        } else if(auto p = std::get_if<StdThread>(&req->thread())){
            TypedID    tid(Thread::standard(*p).id, Type::Thread);
            send(new SaveRequest({.cause=req, .source=*this, .target=tid}, req->tachyons(), req->flags()));
        } else {
            send(new SaveTSXReply({.source = *this, .target=req->source()}, req, Response::InvalidArg));
            return ;
        }
    }
}
