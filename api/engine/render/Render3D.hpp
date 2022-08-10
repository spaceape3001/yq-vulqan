////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/Dirty.hpp>
#include <basic/Object.hpp>
#include <basic/Mutable.hpp>
#include <basic/Ref.hpp>
#include <basic/meta/ObjectInfo.hpp>
#include <engine/render/PipelineConfig.hpp>
#include <engine/render/Rendered.hpp>
#include <math/SimpleSpace.hpp>
#include <math/AxBox3.hpp>

namespace yq {
    namespace engine {
        class Render3D;
        
        class Render3DInfo : public RenderedInfo {
        public:
            template <typename C> struct Writer;

            Render3DInfo(std::string_view, ObjectInfo&, const std::source_location& sl = std::source_location::current());
        };


        /*! \brief Something that's rendered with a defined position, size, etc
        */
        class Render3D : public Rendered {
            YQ_OBJECT_INFO(Render3DInfo);
            YQ_OBJECT_DECLARE(Render3D, Rendered)
        public:    

            //  The model matrix in relation to its parent
            Tensor44D          calc_local() const;
            
            //  Computes the model to world matrix
            glm::dmat4                      model2world() const;
            
            //Render3D*                       parent() { return m_parent; }
            const Render3D*                 parent() const { return m_parent; }
            
            const Vector3D&                 position() const { return m_space->position; }
            const Vector3D&                 scale() const { return m_space->scale; }
            const Quaternion3D&             orientation() const { return m_space->orientation; }
            const AxBox3D&                  bounds() const { return m_bounds; }
            const SimpleSpace&              space() const { return m_space; }
            
            void                            set_position(const Vector3D&);
            void                            set_scale(const Vector3D&);
            void                            set_scaling(double);
            void                            set_orientation(const Quaternion3D&);
            void                            set_heading(Radian hdg);
            void                            set_hpr(Radian hdg, Radian pitch, Radian roll);
            void                            set_bounds(const AxBox3D&);
            void                            set_space(const SimpleSpace&);
            
            virtual Ref<Render3D>           clone() const { return {}; }
            
        protected:
            
            Render3D();
            virtual ~Render3D();
            
        private:
            Mutable<Render3D*>                      m_parent;
            Mutable<std::vector<Ref<Render3D>>>     m_children;
            
            //! This is the coordinate space for the object (position, scale, & orientation)
            Mutable<SimpleSpace>                    m_space;
            
            //! Bounding box of the render object in its x/y/z axis
            Mutable<AxBox3D>                        m_bounds;
        };

    }
}
