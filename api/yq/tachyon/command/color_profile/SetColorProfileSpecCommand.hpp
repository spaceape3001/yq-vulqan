////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/ColorProfileCommand.hpp>

namespace yq::tachyon {
    class SetColorProfileSpecCommand : public ColorProfileCommand {
        YQ_OBJECT_DECLARE(SetColorProfileSpecCommand, ColorProfileCommand)
    public:
        SetColorProfileSpecCommand(const Header&, const std::string&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();
        
        const std::string&     spec() const { return m_spec; }

    protected:
        SetColorProfileSpecCommand(const SetColorProfileSpecCommand&, const Header&);
        virtual ~SetColorProfileSpecCommand();
        
    private:
    
        std::string     m_spec;

        SetColorProfileSpecCommand(const SetColorProfileSpecCommand&) = delete;
        SetColorProfileSpecCommand(SetColorProfileSpecCommand&&) = delete;
        SetColorProfileSpecCommand& operator=(const SetColorProfileSpecCommand&) = delete;
        SetColorProfileSpecCommand& operator=(SetColorProfileSpecCommand&&) = delete;
    };
}
