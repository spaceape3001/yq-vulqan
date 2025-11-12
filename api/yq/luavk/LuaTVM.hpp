////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/lua/LuaVM.hpp>
#include <yq/tachyon/api/Tachyon.hpp>
#include <yq/core/Stream.hpp>

namespace yq::lua {
    class ExecuteStringRequest;
    class ExecuteFileRequest;
    
    struct LuaChannel : public Stream {
        std::string*        buffer  = nullptr;
        virtual bool        write(const char* z, size_t cb);
        
        LuaChannel();
        ~LuaChannel();
    };
    
    class LuaTVM : public tachyon::Tachyon {
        YQ_TACHYON_DECLARE(LuaTVM, tachyon::Tachyon)
    public:
        LuaTVM();
        ~LuaTVM();
        
        static void init_meta();
        
    protected:
        virtual tachyon::Execution   setup(const tachyon::Context&) override;
        virtual tachyon::Execution   tick(const tachyon::Context&) override;
        virtual tachyon::Execution   teardown(const tachyon::Context&) override;

    private:
        lua_State*      m_lua       = nullptr;
        LuaChannel      m_output, m_error, m_warning;
        bool            m_init       = false;
        
        void    on_exec_file(const ExecuteFileRequest&);
        void    on_exec_string(const ExecuteStringRequest&);
    };
}
