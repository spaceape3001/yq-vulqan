////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "FileIOManager.hpp"

#include <yq/core/Any.hpp>

#include <tachyon/logging.hpp>
#include <tachyon/api/ID.hpp>
#include <tachyon/api/ManagerMetaWriter.hpp>
#include <tachyon/api/Thread.hpp>
#include <tachyon/io/Save.hpp>
#include <tachyon/io/save/SaveXML.hpp>
#include <tachyon/reply/io/LoadTSXReply.hpp>
#include <tachyon/reply/io/SaveReply.hpp>
#include <tachyon/reply/io/SaveTSXReply.hpp>
#include <tachyon/request/io/LoadTSXRequest.hpp>
#include <tachyon/request/io/SaveTSXRequest.hpp>
#include <tachyon/request/io/SaveRequest.hpp>

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
        
        SaveXML sxml;
        std::error_code ec  = sxml.load(req->filepath());
        if(ec != std::error_code()){
            tachyonWarning << "FileIOManager: Unable to load tsx file (" << req->filepath() << ") due to: " << ec.message();
            send(new LoadTSXReply({.source=*this, .target=req->source()}, req, Response::IOError));
            return ;
        }
        
        if(!sxml.save){
            tachyonWarning << "FileIOManager: Unable to load tsx file (" << req->filepath() << ")";
            send(new LoadTSXReply({.source=*this, .target=req->source()}, req, Response::IOError));
            return ;
        }
        
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
        
        SaveXML     sxml;
        sxml.save   = rep->save();
        std::error_code ec  = sxml.save_to(req->filepath());
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
            send(new SaveRequest({.cause=req, .source=*this, .target=tid}, req->tachyons(), req->options()));
        } else if(auto p = std::get_if<StdThread>(&req->thread())){
            TypedID    tid(Thread::standard(*p).id, Type::Thread);
            send(new SaveRequest({.cause=req, .source=*this, .target=tid}, req->tachyons(), req->options()));
        } else {
            send(new SaveTSXReply({.source = *this, .target=req->source()}, req, Response::InvalidArg));
            return ;
        }
    }
}
