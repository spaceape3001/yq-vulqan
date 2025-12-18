////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Rendered3.hpp>
#include <yq/tachyon/aspect/ABgColor.hpp>
#include <yq/tachyon/aspect/AColor.hpp>
#include <yq/tachyon/aspect/ADrawMode.hpp>
#include <yq/tachyon/aspect/AMaterial.hpp>
#include <yq/tachyon/aspect/ASize3.hpp>
#include <yq/tachyon/aspect/ATexture.hpp>

#include <yq/typedef/uv.hpp>
#include <yq/typedef/uvw.hpp>
#include <yq/typedef/vector2.hpp>
#include <yq/typedef/vector3.hpp>
#include <yq/typedef/vector4.hpp>

namespace yq::tachyon {
    struct Vertex³;

    struct Shape³Snap;
    struct Shape³Data;
    
    class SetAutoCenterCommand;
    class SetNormalizeCommand;

    
    /*! \brief Abstract shape
    
        This class will remain in the API library as it's intended to be abstract.
        
        \note Updated the name...
        
        \note Derived classes should *ALWAYS* be normalized in size
    */
    class Shape³ : public Rendered³, 
        public ABgColor,
        public AColor,
        public ADrawMode,
        public AMaterial,
        public ASize³,
        public ATexture
    {
        YQ_TACHYON_SNAP(Shape³Snap)
        YQ_TACHYON_DATA(Shape³Data)
        YQ_TACHYON_DECLARE(Shape³, Rendered³)
    public:
    
        /*
            Overhauling the shape object... draw mode coming back into play
            
            ALL draw modes are permitted; if a shape cannot support a particular
            draw mode, it's recourse is to disable the good flag.
            
            Auto        -- select the best one given what's available AND what the
            shape can support.
            
            Color       -- solid color (no UV needed)
            
            BiColor     -- If the material has a grayscale, use it
            
            Gradient    -- Vertices are assigned colors, blend
            
            Texture     -- use the given material for a texture
        */
    
    
        //  TODOs
        //  1) Color functions
        //  2) Bilevel colors (primary/alternate for when that's an issue)
        //  3) Material/Textures

        struct Param : public Rendered³::Param, 
            public ABgColor::Param, 
            public AColor::Param, 
            public ADrawMode::Param,
            public ASize³::Param
        {
            Tristate    auto_center = Tristate::Inherit;
            Tristate    normalize   = Tristate::Inherit;
        };
        
        static void init_meta();

        Execution           setup(const Context&) override;
        Execution           tick(const Context&) override;

        using ADrawMode::draw_mode;
        virtual bool        draw_mode(settable_k) const override { return true; }
        
        using AColor::color;
        virtual bool        color(settable_k) const override { return true; }
        
        //using ABgColor::bgcolor;
        //virtual bool    bgcolor(settable_k) const override { return true; }

        bool             normalize() const;
        bool             auto_center() const;

    protected:
    
        Shape³(const Param&);
        ~Shape³();
    
        struct VertexC {
            glm::vec4   color;
            glm::vec3   position;
        };
        
        struct VertexT {
            glm::vec3   position;
            glm::vec2   uv;
        };
        
        struct VertexCT {
            glm::vec4   color;
            glm::vec3   position;
            glm::vec2   uv;
        };
        
        struct VertexS {
            glm::vec3   position;
        };

        struct Uniform {
            //! Color of the object
            glm::vec4       color   = {0.5,0.5,0.5,1.};
            
            //! Alt/Background color of the object
            glm::vec4       bgcolor = {0.5,0.5,0.5,1.};
            
            //! Color multiplier (standard frag shader)
            //! Allows for brightness more/less to color
            //! Zero & a fixed value to ca overrides
            glm::vec4       fx      = {1.,1.,1.,1.};
            
            //! Color base
            glm::vec4       fa      = {0.,0.,0.,0.};
            
            //  might add more...same idea
        };
        
        using UBS  = Uniform;

        static glm::vec3        gfx(const RGB3F&);
        static glm::vec4        gfx(const RGBA4F&);
        static glm::vec2        gfx(const UV2F&);
        static glm::vec3        gfx(const UVW3F&);
        static glm::dvec2       gfx(const Vector2D&);
        static glm::vec2        gfx(const Vector2F&);
        static glm::dvec3       gfx(const Vector3D&);
        static glm::vec3        gfx(const Vector3F&);
        static glm::vec4        gfx(const Vector4F&);
        static glm::dvec4       gfx(const Vector4D&);

        static VertexC          vc(const Vertex³&);
        static VertexCT         vct(const Vertex³&);
        static VertexT          vt(const Vertex³&);
        static VertexS          vs(const Vertex³&v);
        
        static VertexC          vtx(const Vector3D&, const RGBA4F&);
        static VertexC          vtx(const Vector3F&, const RGBA4F&);
        static VertexT          vtx(const Vector3D&, const UV2F&t);
        static VertexT          vtx(const Vector3F&, const UV2F&t);
        static VertexCT         vtx(const Vector3D&, const RGBA4F&, const UV2F&);
        static VertexCT         vtx(const Vector3F&, const RGBA4F&, const UV2F&);
        static VertexS          vtx(const Vector3D&);
        static VertexS          vtx(const Vector3F&);

        Tristate        m_autoCenter    = Tristate::Inherit;
        Tristate        m_normalize     = Tristate::Inherit;

        #if 0
        //  We're going to add variations as necessary, but try to reuse them... 
        
        VB1<VertexC>    m_vertexC;
        VB1<VertexCT>   m_vertexCT;
        VB1<VertexT>    m_vertexT;
        VB1<VertexS>    m_vertexS;
        
        UB1<UBS>        m_uniformS;
        TextureCPtr     m_texture;
        #endif
        

        std::error_code     load(const StateSave&) override;
        
        void snap(Shape³Snap&) const;
        
        
        //template <typename C>
        //requires std::is_base_of<C,Shape³>
        //static void     pipeline_color(

        // Called whenever we've been marked "dirty" and need to rebuild the render buffers
        virtual void    rebuild(){}
        
    private:
        void on_set_auto_center_command(const SetAutoCenterCommand&);
        void on_set_normalize_command(const SetNormalizeCommand&);
    };
}

YQ_TACHYON_FORCE(yq::tachyon::Shape³)
