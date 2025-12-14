////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/MeshCommand.hpp>
#include <yq/tachyon/typedef/texture.hpp>
#include <yq/net/Url.hpp>

namespace yq::tachyon {
    class SetMeshUrlCommand : public MeshCommand {
        YQ_OBJECT_DECLARE(SetMeshUrlCommand, MeshCommand)
    public:
        SetMeshUrlCommand(const Header&, const Url&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();
        
        const Url&     url() const { return m_url; }

    protected:
        SetMeshUrlCommand(const SetMeshUrlCommand&, const Header&);
        virtual ~SetMeshUrlCommand();
        
    private:
    
        Url     m_url;

        SetMeshUrlCommand(const SetMeshUrlCommand&) = delete;
        SetMeshUrlCommand(SetMeshUrlCommand&&) = delete;
        SetMeshUrlCommand& operator=(const SetMeshUrlCommand&) = delete;
        SetMeshUrlCommand& operator=(SetMeshUrlCommand&&) = delete;
    };
}
