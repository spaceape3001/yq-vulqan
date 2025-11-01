////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/request/IORequest.hpp>
#include <tachyon/api/ID.hpp>
#include <tachyon/api/StdThread.hpp>
#include <filesystem>

namespace yq::tachyon {
    class LoadTSXRequest : public IORequest {
        YQ_OBJECT_DECLARE(LoadTSXRequest, IORequest)
    public:
        static void init_meta();
        
        using PrepFN    = std::function<void()>;
        
        /*! \brief Creates a load request
        
            \note Any Prep FN will be executed on the callee's thread!
        */
        LoadTSXRequest(const Header&, const std::filesystem::path&, ThreadSpec, PrepFN&& fn={});
        PostCPtr clone(rebind_k, const Header&) const override;
        
        const std::filesystem::path&    filepath() const { return m_filepath; }
        const ThreadSpec&               thread() const { return m_thread; }
        const PrepFN&                   prep() const { return m_prep; }

    protected:
        LoadTSXRequest(const LoadTSXRequest&, const Header&);
        ~LoadTSXRequest();

    private:
        std::filesystem::path   m_filepath;
        ThreadSpec              m_thread;
        PrepFN                  m_prep;

        LoadTSXRequest(const LoadTSXRequest&) = delete;
        LoadTSXRequest(LoadTSXRequest&&) = delete;
        LoadTSXRequest& operator=(const LoadTSXRequest&) = delete;
        LoadTSXRequest& operator=(LoadTSXRequest&&) = delete;
    };

}
