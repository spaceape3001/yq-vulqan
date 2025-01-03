////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Rendered.hpp>
#include <yq/math/SimpleSpace.hpp>
#include <yq/shape/AxBox3.hpp>

namespace yq::tachyon {
        
    /*! \brief Information for the render3D object
    */
    class Render³DInfo : public RenderedInfo {
    public:
        template <typename C> struct Writer;

        Render³DInfo(std::string_view, RenderedInfo&, const std::source_location& sl = std::source_location::current());
    };

    /*! \brief Something that's rendered with a defined position, size, etc
    */
    class Render³D : public Rendered {
        YQ_TACHYON_INFO(Render³DInfo);
        YQ_TACHYON_DECLARE(Render³D, Rendered)
    public:    

        //  The model matrix in relation to its parent
        Tensor44D                       calc_local() const;
        
        //  Computes the model to world matrix
        glm::dmat4                      model2world() const;
        
        //Render³D*                       parent() { return m_parent; }
        
        //! Parent of this render object
        const Render³D*                 parent() const { return m_parent; }
        
        //! Position of the render object
        const Vector3D&                 position() const { return m_space.position; }
        
        //! Scale of the render object
        const Vector3D&                 scale() const { return m_space.scale; }
        
        //! Orientation of the render object
        const Quaternion3D&             orientation() const { return m_space.orientation; }
        
        //! Bounds of the render object
        const AxBox3D&                  bounds() const { return m_bounds; }
        
        //! Space of the render object
        const SimpleSpace&              space() const { return m_space; }
        
        //! Set the position of the render object
        void                            set_position(const Vector3D&);
        
        //! Set the scale of the render object
        void                            set_scale(const Vector3D&);
        
        //! Convienent single-setting set of scale 
        //! 
        //! Equivalent to Vector3D(ALL, v)
        void                            set_scaling(double);
        
        //! Set the orientation of the render object
        void                            set_orientation(const Quaternion3D&);
        
        //! Sets the heading of the object (equivlent to creating a quaternion and setting)
        void                            set_heading(Radian hdg);
        //! Sets the heading, pitch, roll of the object (equivlent to creating a quaternion and setting)
        void                            set_hpr(Radian hdg, Radian pitch, Radian roll);
        
        //! Sets the bounds of the render object
        void                            set_bounds(const AxBox3D&);
        
        //! Sets the space of the render object
        void                            set_space(const SimpleSpace&);
        
        //! Generic clone routine, to be implemented by the derived object
        //virtual Ref<Render³D>           clone() const { return {}; }
        
        /*! \brief Sets the parent of this widget
        
            This will fail if a parent-loop is detected.  
            (ie, trying to set to self)
        
            \param[in] p    Proposed parent (can be null)
            \return TRUE if the change was taken
        */
        //bool                            set_parent(Widget* p);
        
        /*! \brief Adds the child to this widget
        
            This will fail for reasons of set_parent, OR the
            child is null.
            
            \param[in] ch   Child to add
            \return TRUE if the change was taken
        */
        //bool                            add_child(Widget* ch);
        
        /*! \brief Tests for parentage
        
            Checks to see if the argument is this widget's parent
            or grandparent or great grandparent to whatever degree.
        
            \param p    Supposed parent in question
        */
        //bool                            has_parentage(const Widget* p) const;

        static void init_info();

    protected:
        
        Render³D(const Param&p={});
        virtual ~Render³D();
        
    private:
        Render³D*                      m_parent;
        std::vector<Ref<Render³D>>     m_children;
        
        //! This is the coordinate space for the object (position, scale, & orientation)
        SimpleSpace                    m_space;
        
        //! Bounding box of the render object in its x/y/z axis
        AxBox3D                        m_bounds;
    };

}
