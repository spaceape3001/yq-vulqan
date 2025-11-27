////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/ShapeCommand.hpp>
#include <yq/tachyon/typedef/mesh.hpp>

namespace yq::tachyon {
    class SetMeshCommand : public ShapeCommand {
        YQ_OBJECT_DECLARE(SetMeshCommand, ShapeCommand)
    public:
        SetMeshCommand(const Header&, const MeshCPtr&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();
        
        const MeshCPtr&     mesh() const { return m_mesh; }

    protected:
        SetMeshCommand(const SetMeshCommand&, const Header&);
        virtual ~SetMeshCommand();
        
    private:
    
        MeshCPtr            m_mesh;

        SetMeshCommand(const SetMeshCommand&) = delete;
        SetMeshCommand(SetMeshCommand&&) = delete;
        SetMeshCommand& operator=(const SetMeshCommand&) = delete;
        SetMeshCommand& operator=(SetMeshCommand&&) = delete;
    };
}
