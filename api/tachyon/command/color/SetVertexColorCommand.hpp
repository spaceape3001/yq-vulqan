////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/ColorCommand.hpp>
#include <yq/color/RGBA.hpp>

namespace yq::tachyon {
    class SetVertexColorCommand : public ColorCommand {
        YQ_OBJECT_DECLARE(SetVertexColorCommand, ColorCommand)
    public:
        SetVertexColorCommand(const Header&, unsigned, const RGBA4F&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        const RGBA4F&   bgcolor() const { return m_bgColor; }
        void            set_bgcolor(const RGBA4F&);
        
        //! Number relevant to the shape (ie, for triangles it's 1...2...3)
        unsigned        vertex() const { return m_vertex; }
        void            set_vertex(unsigned);

        static void init_info();

    protected:
        SetVertexColorCommand(const SetVertexColorCommand&, const Header&);
        virtual ~SetVertexColorCommand();
        
    private:
    
        RGBA4F      m_bgColor;
        unsigned    m_vertex;

        SetVertexColorCommand(const SetVertexColorCommand&) = delete;
        SetVertexColorCommand(SetVertexColorCommand&&) = delete;
        SetVertexColorCommand& operator=(const SetVertexColorCommand&) = delete;
        SetVertexColorCommand& operator=(SetVertexColorCommand&&) = delete;
    };
}
