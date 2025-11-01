////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/VertexCommand.hpp>
#include <yq/color/RGBA.hpp>

namespace yq::tachyon {
    class SetVertexColorCommand : public VertexCommand {
        YQ_OBJECT_DECLARE(SetVertexColorCommand, VertexCommand)
    public:
        SetVertexColorCommand(const Header&, size_t, const RGBA4F&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        const RGBA4F&   color() const { return m_color; }
        void            set_color(const RGBA4F&);
        
        float           red() const { return m_color.red; }
        float           green() const { return m_color.green; }
        float           blue() const { return m_color.blue; }
        float           alpha() const { return m_color.alpha; }
        
        //! Number relevant to the shape (ie, for triangles it's 1...2...3)
        size_t          vertex() const { return m_vertex; }
        void            set_vertex(size_t);

        static void init_meta();

    protected:
        SetVertexColorCommand(const SetVertexColorCommand&, const Header&);
        virtual ~SetVertexColorCommand();
        
    private:
    
        RGBA4F      m_color;
        size_t      m_vertex;

        SetVertexColorCommand(const SetVertexColorCommand&) = delete;
        SetVertexColorCommand(SetVertexColorCommand&&) = delete;
        SetVertexColorCommand& operator=(const SetVertexColorCommand&) = delete;
        SetVertexColorCommand& operator=(SetVertexColorCommand&&) = delete;
    };
}
