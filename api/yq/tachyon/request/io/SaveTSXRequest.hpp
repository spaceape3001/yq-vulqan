////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/request/IORequest.hpp>
#include <tachyon/api/ID.hpp>
#include <tachyon/api/StdThread.hpp>
#include <tachyon/typedef/save.hpp>
#include <filesystem>

namespace yq::tachyon {
    class SaveTSXRequest : public IORequest {
        YQ_OBJECT_DECLARE(SaveTSXRequest, IORequest)
    public:
        static void init_meta();
        
        SaveTSXRequest(const Header&, const std::filesystem::path&, ThreadSpec, SaveOptions opts={});
        SaveTSXRequest(const Header&, const std::filesystem::path&, ThreadSpec, const TachyonIDSet&, SaveOptions opts={});
        SaveTSXRequest(const Header&, const std::filesystem::path&, ThreadSpec, TachyonIDSet&&, SaveOptions opts={});
        SaveTSXRequest(const SaveTSXRequest&, const Header&);
        
        const std::filesystem::path&    filepath() const { return m_filepath; }
        const ThreadSpec&               thread() const { return m_thread; }
        const TachyonIDSet&             tachyons() const { return m_tachyons; }
        SaveOptions                     options() const { return m_options; }
        
    protected:
        virtual PostCPtr clone(rebind_k, const Header&) const;
        virtual ~SaveTSXRequest();
        
    private:
        std::filesystem::path   m_filepath;
        ThreadSpec              m_thread;
        TachyonIDSet            m_tachyons;
        SaveOptions             m_options;

        SaveTSXRequest(const SaveTSXRequest&) = delete;
        SaveTSXRequest(SaveTSXRequest&&) = delete;
        SaveTSXRequest& operator=(const SaveTSXRequest&) = delete;
        SaveTSXRequest& operator=(SaveTSXRequest&&) = delete;
    };
}
