////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/request/IORequest.hpp>
#include <yq/tachyon/api/ID.hpp>
#include <yq/tachyon/api/StdThread.hpp>
#include <yq/tachyon/enum/SaveFlags.hpp>
#include <filesystem>

namespace yq::tachyon {
    class SaveTSXRequest : public IORequest {
        YQ_OBJECT_DECLARE(SaveTSXRequest, IORequest)
    public:
        static void init_meta();
        
        struct Config {
            ThreadSpec          thread;
            TachyonIDSet        tachyons;
            SaveFlags           flags;
        };
        
        
        SaveTSXRequest(const Header&, const std::filesystem::path&, const Config&);
        SaveTSXRequest(const SaveTSXRequest&, const Header&);
        
        const std::filesystem::path&    filepath() const { return m_filepath; }
        const Config&                   config() const { return m_config; }
        const ThreadSpec&               thread() const { return m_config.thread; }
        const TachyonIDSet&             tachyons() const { return m_config.tachyons; }
        SaveFlags                       flags() const { return m_config.flags; }
        
    protected:
        virtual PostCPtr clone(rebind_k, const Header&) const;
        virtual ~SaveTSXRequest();
        
    private:
    
        std::filesystem::path   m_filepath;
        Config                  m_config;

        SaveTSXRequest(const SaveTSXRequest&) = delete;
        SaveTSXRequest(SaveTSXRequest&&) = delete;
        SaveTSXRequest& operator=(const SaveTSXRequest&) = delete;
        SaveTSXRequest& operator=(SaveTSXRequest&&) = delete;
    };
}
