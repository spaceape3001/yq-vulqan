////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/MeshCommand.hpp>

namespace yq::tachyon {
    class SetMeshSpecCommand : public MeshCommand {
        YQ_OBJECT_DECLARE(SetMeshSpecCommand, MeshCommand)
    public:
        SetMeshSpecCommand(const Header&, const std::string&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();
        
        const std::string&     spec() const { return m_spec; }

    protected:
        SetMeshSpecCommand(const SetMeshSpecCommand&, const Header&);
        virtual ~SetMeshSpecCommand();
        
    private:
    
        std::string     m_spec;

        SetMeshSpecCommand(const SetMeshSpecCommand&) = delete;
        SetMeshSpecCommand(SetMeshSpecCommand&&) = delete;
        SetMeshSpecCommand& operator=(const SetMeshSpecCommand&) = delete;
        SetMeshSpecCommand& operator=(SetMeshSpecCommand&&) = delete;
    };
}
