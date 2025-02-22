////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/IOCommand.hpp>
#include <yt/typedef/tachyon.hpp>
#include <yt/api/StdThread.hpp>
#include <yt/api/TypedID.hpp>
#include <yt/typedef/save.hpp>
#include <filesystem>

namespace yq::tachyon {
    class SaveCommand : public IOCommand {
        YQ_OBJECT_DECLARE(SaveCommand, IOCommand)
    public:
        struct Param {
            SaveOptions             options;
            TachyonIDSet            tachyons;   //< Tachyons to save (leave blank for all)
            TypedID                 thread;     //< Thread to save from
        };
    
        SaveCommand(const Header&, const std::filesystem::path&);
        SaveCommand(const Header&, const std::filesystem::path&, const Param& p);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_info();
        
        const std::filesystem::path& filepath() const { return m_filepath; }
        
        TypedID     thread() const { return m_thread; }
        const TachyonIDSet& tachyons() const { return m_tachyons; }
        SaveOptions         options() const { return m_options; }

    protected:
        SaveCommand(const SaveCommand&, const Header&);
        virtual ~SaveCommand();
        
    private:
        std::filesystem::path       m_filepath;
        TachyonIDSet                m_tachyons;
        TypedID                     m_thread;
        SaveOptions                 m_options;

        SaveCommand(const SaveCommand&) = delete;
        SaveCommand(SaveCommand&&) = delete;
        SaveCommand& operator=(const SaveCommand&) = delete;
        SaveCommand& operator=(SaveCommand&&) = delete;
    };
}
