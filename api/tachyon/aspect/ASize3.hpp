////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/interface/ISize3.hpp>
#include <tachyon/api/Tachyon.hpp>

namespace yq::tachyon {

    class AddSize³Command;
    class AddSizeˣCommand;
    class AddSizeʸCommand;
    class AddSizeᶻCommand;
    class MultiplySize;
    class MultiplySize³Command;
    class MultiplySizeˣCommand;
    class MultiplySizeʸCommand;
    class MultiplySizeᶻCommand;
    class SetSize³Command;
    class SetSizeˣCommand;
    class SetSizeʸCommand;
    class SetSizeᶻCommand;

    class ASize³ : public ISize³, public virtual Tachyon::Helper {
    public:
    
        //!  Basic size in the 3D space
        Size3D          size() const override { return m_size; }
        
        double          size(x_k) const { return m_size.x; }
        double          size(y_k) const { return m_size.y; }
        double          size(z_k) const { return m_size.z; }
        
        //!  Set size the size (OVERRIDE THIS TO INTERCEPT/REJECT)
        virtual void    size(set_k, const Size3D&) override;
        void            size(set_k, x_k, double) override;
        void            size(set_k, y_k, double) override;
        void            size(set_k, z_k, double) override;
        
        //!  Move the size (ie set to size + delta)
        void            size(add_k, const Vector3D&) override;
        void            size(add_k, x_k, double) override;
        void            size(add_k, y_k, double) override;
        void            size(add_k, z_k, double) override;

        void            size(multiply_k, double) override;
        void            size(multiply_k, const Vector3D&) override;
        void            size(multiply_k, x_k, double) override;
        void            size(multiply_k, y_k, double) override;
        void            size(multiply_k, z_k, double) override;
        
        bool            size(disabled_k) const { return false; }
        bool            size(settable_k) const { return true; }
        bool            size(addable_k) const { return true; }
        bool            size(multipliable_k) const { return true; }
        
        const Size3D&   size(ref_k) const { return m_size; }

    protected:
    
        static constexpr const Size3D   kDefSize    = ONE;

        Size3D      m_size = kDefSize;
        
        template <typename C>
        static void init_meta(TachyonMeta::Writer<C>&);
        
        ASize³();
        virtual ~ASize³();
        
        void        size(emit_k);
        
    private:
        void        on_set_size3(const SetSize³Command&);
        void        on_set_sizeX(const SetSizeˣCommand&);
        void        on_set_sizeY(const SetSizeʸCommand&);
        void        on_set_sizeZ(const SetSizeᶻCommand&);

        void        on_add_size3(const AddSize³Command&);
        void        on_add_sizeX(const AddSizeˣCommand&);
        void        on_add_sizeY(const AddSizeʸCommand&);
        void        on_add_sizeZ(const AddSizeᶻCommand&);
        
        void        on_multiply_size(const MultiplySize&);
        void        on_multiply_size3(const MultiplySize³Command&);
        void        on_multiply_sizeX(const MultiplySizeˣCommand&);
        void        on_multiply_sizeY(const MultiplySizeʸCommand&);
        void        on_multiply_sizeZ(const MultiplySizeᶻCommand&);

    };

}
