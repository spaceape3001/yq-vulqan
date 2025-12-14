////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/HeightFieldCommand.hpp>

namespace yq::tachyon {
    class SetHeightFieldSpecCommand : public HeightFieldCommand {
        YQ_OBJECT_DECLARE(SetHeightFieldSpecCommand, HeightFieldCommand)
    public:
        SetHeightFieldSpecCommand(const Header&, const std::string&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();
        
        const std::string&     spec() const { return m_spec; }

    protected:
        SetHeightFieldSpecCommand(const SetHeightFieldSpecCommand&, const Header&);
        virtual ~SetHeightFieldSpecCommand();
        
    private:
    
        std::string     m_spec;

        SetHeightFieldSpecCommand(const SetHeightFieldSpecCommand&) = delete;
        SetHeightFieldSpecCommand(SetHeightFieldSpecCommand&&) = delete;
        SetHeightFieldSpecCommand& operator=(const SetHeightFieldSpecCommand&) = delete;
        SetHeightFieldSpecCommand& operator=(SetHeightFieldSpecCommand&&) = delete;
    };
}
