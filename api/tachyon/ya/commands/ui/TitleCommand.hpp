////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/UICommand.hpp>

namespace yq::tachyon {
    class TitleCommand : public UICommand {
        YQ_OBJECT_DECLARE(TitleCommand, UICommand)
    public:
        TitleCommand(const Header&, std::string_view szTitle);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        const std::string&    title() const { return m_title; }

        static void init_info();

    protected:
        TitleCommand(const TitleCommand&, const Header&);
        virtual ~TitleCommand();
        
    private:
        std::string     m_title;

        TitleCommand(const TitleCommand&) = delete;
        TitleCommand(TitleCommand&&) = delete;
        TitleCommand& operator=(const TitleCommand&) = delete;
        TitleCommand& operator=(TitleCommand&&) = delete;
    };
}
