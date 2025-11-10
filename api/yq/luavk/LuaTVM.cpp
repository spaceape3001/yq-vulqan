////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "LuaTVM.hpp"

#include <yq/lua/logging.hpp>
#include <yq/lua/lualua.hxx>
#include <yq/lua/keys.hpp>
#include <yq/luavk/command/ExecuteFileCommand.hpp>
#include <yq/luavk/command/ExecuteStringCommand.hpp>
#include <yq/luavk/event/ExecuteFileEvent.hpp>
#include <yq/luavk/event/ExecuteStringEvent.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>

#include <iostream>

YQ_TACHYON_IMPLEMENT(yq::lua::LuaTVM)

namespace yq::lua {
    LuaChannel::LuaChannel()
    {
    }
    
    LuaChannel::~LuaChannel()
    {
    }
    
    bool   LuaChannel::write(const char* buf, size_t cb)
    {
        if(buffer && buf && cb){
            *buffer += std::string_view(buf, cb);
        }
        return true;
    }

    static void tvmLuaWarning(void*ud, const char* msg, int)
    {
        if(ud)
            (*(LuaChannel*) ud) << msg;
    }


    LuaTVM::LuaTVM()
    {
        m_lua   = luaL_newstate();
        lua_setwarnf(m_lua, tvmLuaWarning, &m_warning);
        luaL_openlibs(m_lua);
        lua::set(m_lua, GLOBAL, lua::keyOutput, RAW, &m_output);
        lua::set(m_lua, GLOBAL, lua::keyError, RAW, &m_error);
        lua::set(m_lua, GLOBAL, lua::keyWarning, RAW, &m_warning);
        lua::configure(m_lua);
    }
    
    LuaTVM::~LuaTVM()
    {
        if(m_lua){
            lua_close(m_lua);
            m_lua   = nullptr;
        }
    }

    void    LuaTVM::on_exec_file(const ExecuteFileCommand& cmd)
    {
        if(!m_lua)
            return;
            
        luaInfo << "Execute file: " << cmd.file();    
        std::string     error, warning, output;
        m_output.buffer     = &output;
        m_warning.buffer    = &warning;
        m_error.buffer      = &error;

        auto ec = luaL_dofile(m_lua, cmd.file().c_str()) ? errors::lua_runtime() : std::error_code();;
        m_output.buffer = m_warning.buffer = m_error.buffer = nullptr;
        
        send(new ExecuteFileEvent({.cause=&cmd}, cmd.file(), std::move(output), std::move(warning), std::move(error), ec));
    }

    void    LuaTVM::on_exec_string(const ExecuteStringCommand& cmd)
    {
        if(!m_lua)
            return;

        std::string     error, warning, output;
        m_output.buffer     = &output;
        m_warning.buffer    = &warning;
        m_error.buffer      = &error;

        auto ec = luaL_dostring(m_lua, cmd.text().c_str()) ? errors::lua_runtime() : std::error_code();
        m_output.buffer = m_warning.buffer = m_error.buffer = nullptr;

        send(new ExecuteStringEvent({.cause=&cmd}, cmd.text(), std::move(output), std::move(warning), std::move(error), ec));
    }

    tachyon::Execution   LuaTVM::setup(const tachyon::Context&ctx) 
    {
        if(m_init)
            return tachyon::Tachyon::setup(ctx);
        
        //  TODO
        
        return tachyon::Tachyon::setup(ctx); 
    }
    
    tachyon::Execution   LuaTVM::tick(const tachyon::Context&ctx) 
    {
        return tachyon::Tachyon::tick(ctx);
    }
    
    tachyon::Execution   LuaTVM::teardown(const tachyon::Context&ctx) 
    {
        if(!m_init)
            return tachyon::Tachyon::teardown(ctx);
    
        // TODO
        
        return tachyon::Tachyon::teardown(ctx);
    }
        
    void LuaTVM::init_meta()
    {
        auto w = writer<LuaTVM>();
        w.description("Lua Tachyon-Based Virtual Machine");
        w.slot(&LuaTVM::on_exec_file);
        w.slot(&LuaTVM::on_exec_string);
    }
}
