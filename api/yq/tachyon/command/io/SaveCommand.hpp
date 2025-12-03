////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/IOCommand.hpp>
#include <yq/tachyon/typedef/tachyon.hpp>
#include <yq/tachyon/api/StdThread.hpp>
#include <yq/tachyon/api/TypedID.hpp>
#include <yq/tachyon/enum/SaveFlags.hpp>
#include <yq/tachyon/typedef/save.hpp>
#include <filesystem>

namespace yq::tachyon {
    class SaveCommand : public IOCommand {
        YQ_OBJECT_DECLARE(SaveCommand, IOCommand)
    public:
        struct Param {
            SaveFlags               flags;
            TachyonIDSet            tachyons;   //< Tachyons to save (leave blank for all)
            TypedID                 thread;     //< Thread to save from
        };
    
        SaveCommand(const Header&, const std::filesystem::path&);
        SaveCommand(const Header&, const std::filesystem::path&, const Param& p);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();
        
        const std::filesystem::path&    filepath() const { return m_filepath; }
        SaveFlags                       flags() const { return m_flags; }
        const TachyonIDSet&             tachyons() const { return m_tachyons; }
        TypedID                         thread() const { return m_thread; }

    protected:
        SaveCommand(const SaveCommand&, const Header&);
        virtual ~SaveCommand();
        
    private:
        std::filesystem::path       m_filepath;
        SaveFlags                   m_flags;
        TachyonIDSet                m_tachyons;
        TypedID                     m_thread;

        SaveCommand(const SaveCommand&) = delete;
        SaveCommand(SaveCommand&&) = delete;
        SaveCommand& operator=(const SaveCommand&) = delete;
        SaveCommand& operator=(SaveCommand&&) = delete;
    };
}
