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
        
        SaveTSXRequest(const Header&, const std::filesystem::path&, ThreadSpec, SaveFlags opts={});
        SaveTSXRequest(const Header&, const std::filesystem::path&, ThreadSpec, const TachyonIDSet&, SaveFlags opts={});
        SaveTSXRequest(const Header&, const std::filesystem::path&, ThreadSpec, TachyonIDSet&&, SaveFlags opts={});
        SaveTSXRequest(const SaveTSXRequest&, const Header&);
        
        const std::filesystem::path&    filepath() const { return m_filepath; }
        const ThreadSpec&               thread() const { return m_thread; }
        const TachyonIDSet&             tachyons() const { return m_tachyons; }
        SaveFlags                       flags() const { return m_flags; }
        
    protected:
        virtual PostCPtr clone(rebind_k, const Header&) const;
        virtual ~SaveTSXRequest();
        
    private:
        std::filesystem::path   m_filepath;
        ThreadSpec              m_thread;
        TachyonIDSet            m_tachyons;
        SaveFlags               m_flags;

        SaveTSXRequest(const SaveTSXRequest&) = delete;
        SaveTSXRequest(SaveTSXRequest&&) = delete;
        SaveTSXRequest& operator=(const SaveTSXRequest&) = delete;
        SaveTSXRequest& operator=(SaveTSXRequest&&) = delete;
    };
}
