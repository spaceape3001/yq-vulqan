////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/TachyonCommand.hpp>

namespace yq::tachyon {
    class SetNameCommand : public TachyonCommand {
        YQ_OBJECT_DECLARE(SetNameCommand, TachyonCommand)
    public:
        SetNameCommand(const Header&, std::string&&);
        SetNameCommand(const Header&, std::string_view);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();
        
        const std::string&  name() const { return m_name; }

    protected:
        SetNameCommand(const SetNameCommand&, const Header&);
        virtual ~SetNameCommand();
        
    private:
    
        std::string     m_name;

        SetNameCommand(const SetNameCommand&) = delete;
        SetNameCommand(SetNameCommand&&) = delete;
        SetNameCommand& operator=(const SetNameCommand&) = delete;
        SetNameCommand& operator=(SetNameCommand&&) = delete;
    };
}
