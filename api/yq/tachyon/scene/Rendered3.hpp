////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/math/SimpleSpace.hpp>
#include <yq/shape/AxBox3.hpp>
#include <yq/shape/Sphere3.hpp>
#include <yq/tachyon/scene/Rendered.hpp>
#include <yq/tachyon/typedef/bounds3.hpp>
#include <yq/tachyon/typedef/rendered3.hpp>
#include <yq/tachyon/typedef/spatial3.hpp>
#include <yq/vector/Quaternion3.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {
        
    /*! \brief Information for the render3D object
    */
    class Rendered³Info : public RenderedInfo {
    public:
        template <typename C> struct Writer;

        Rendered³Info(std::string_view, RenderedInfo&, const std::source_location& sl = std::source_location::current());
    };

    /*! \brief Something that's rendered with a defined position, size, etc
    
    
        \note ONCE it's here, it's considered "fixed" into abstract graphical units.
    */
    class Rendered³ : public Rendered {
        YQ_TACHYON_INFO(Rendered³Info);
        YQ_TACHYON_DATA(Rendered³Data);
        YQ_TACHYON_SNAP(Rendered³Snap);
        YQ_TACHYON_DECLARE(Rendered³, Rendered)
    public:    
    
        struct Param : public Rendered::Param {
            
            // setting *ANY* of these creates a simple spatial (3D)
        
            Vector3D        position        = NAN;
            Quaternion3D    orientation     = NAN;
            Vector3D        scale           = NAN;
        };
    
        Spatial³ID                      spatial3() const { return m_spatial; }
        
        void    set_bounds(bounds3_t);
        void    set_spatial(Spatial³ID);
    
    
        //! Creates/sets a position (NOTE NOT THREAD SAFE!)
        void    set_spatial(
            const Vector3D& position,
            const Quaternion3D& orientation=IDENTITY,
            const Vector3D& scale=ONE
        );
    
        /*
            Really been overthinking this... for *NOW* the rendered will be in full control, 
            however, think it'll be moving to a delegate based system (TBD)
        */
    

        //  The model matrix in relation to its parent
        //Tensor44D                       calc_local() const;
        
        //  Computes the model to world matrix
        //glm::dmat4                      model2world() const;
        
        //Rendered3*                       parent() { return m_parent; }
        
        //! Parent of this render object
        //const Rendered³*                 parent() const { return m_parent; }
        
        //! Position of the render object
        //const Vector3D&                 position() const { return m_space.position; }
        
        //! Scale of the render object
        //const Vector3D&                 scale() const { return m_space.scale; }
        
        //! Orientation of the render object
        //const Quaternion3D&             orientation() const { return m_space.orientation; }
        
        //! Bounds of the render object
        //const AxBox3D&                  bounds() const { return m_bounds; }
        
        //! Space of the render object
        //const SimpleSpace&              space() const { return m_space; }
        
        //! Set the position of the render object
        //void                            set_position(const Vector3D&);
        
        //! Set the scale of the render object
        //void                            set_scale(const Vector3D&);
        
        //! Convienent single-setting set of scale 
        //! 
        //! Equivalent to Vector3D(ALL, v)
        //void                            set_scaling(double);
        
        //! Set the orientation of the render object
        //void                            set_orientation(const Quaternion3D&);
        
        //! Sets the heading of the object (equivlent to creating a quaternion and setting)
        //void                            set_heading(Radian hdg);
        //! Sets the heading, pitch, roll of the object (equivlent to creating a quaternion and setting)
        //void                            set_hpr(Radian hdg, Radian pitch, Radian roll);
        
        //! Sets the bounds of the render object
        //void                            set_bounds(const AxBox3D&);
        
        //! Sets the space of the render object
        //void                            set_space(const SimpleSpace&);
        
        //! Generic clone routine, to be implemented by the derived object
        //virtual Ref<Rendered³>           clone() const { return {}; }
        
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
        
        Rendered³(const Param&);
        virtual ~Rendered³();
        
        void    snap(Rendered³Snap&) const;
        virtual PostAdvice  advise(const Post&) const override;
        
    private:
        Spatial³ID      m_spatial;
        
        //! Bounds of the item (in render coordinate)
        bounds3_t       m_bounds;
    };

}
