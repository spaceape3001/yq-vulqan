////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/TachyonCommand.hpp>
#include <variant>
#include <yq/core/Any.hpp>

namespace yq::tachyon {
    class SetAttributeCommand : public TachyonCommand {
        YQ_OBJECT_DECLARE(SetAttributeCommand, TachyonCommand)
    public:
    
        using key_spec_t = std::variant<std::monostate, int, std::string>;
    
        SetAttributeCommand(const Header&, key_spec_t, const Any&);        
        SetAttributeCommand(const Header&, key_spec_t, Any&&);        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();
        
        const key_spec_t&   key() const { return m_key; }
        const Any&          value() const { return m_value; }

    protected:
        SetAttributeCommand(const SetAttributeCommand&, const Header&);
        virtual ~SetAttributeCommand();
        
    private:
    
        key_spec_t      m_key;
        Any             m_value;

        SetAttributeCommand(const SetAttributeCommand&) = delete;
        SetAttributeCommand(SetAttributeCommand&&) = delete;
        SetAttributeCommand& operator=(const SetAttributeCommand&) = delete;
        SetAttributeCommand& operator=(SetAttributeCommand&&) = delete;
    };
}
