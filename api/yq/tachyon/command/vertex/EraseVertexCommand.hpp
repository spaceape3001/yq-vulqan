////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/VertexCommand.hpp>

namespace yq::tachyon {
    class EraseVertexCommand : public VertexCommand {
        YQ_OBJECT_DECLARE(EraseVertexCommand, VertexCommand)
    public:
        EraseVertexCommand(const Header&, size_t);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        //! Number relevant to the shape (ie, for triangles it's 1...2...3)
        size_t          vertex() const { return m_vertex; }
        void            set_vertex(size_t);

        static void init_meta();

    protected:
        EraseVertexCommand(const EraseVertexCommand&, const Header&);
        virtual ~EraseVertexCommand();
        
    private:
    
        size_t      m_vertex;

        EraseVertexCommand(const EraseVertexCommand&) = delete;
        EraseVertexCommand(EraseVertexCommand&&) = delete;
        EraseVertexCommand& operator=(const EraseVertexCommand&) = delete;
        EraseVertexCommand& operator=(EraseVertexCommand&&) = delete;
    };
}
