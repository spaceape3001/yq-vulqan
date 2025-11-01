////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/interface/IMaxSize3.hpp>
#include <yq/tachyon/api/Tachyon.hpp>

#ifdef NAN
#undef NAN
#endif

namespace yq::tachyon {

    class AddMaxSize³Command;
    class AddMaxSizeˣCommand;
    class AddMaxSizeʸCommand;
    class AddMaxSizeᶻCommand;
    class MultiplyMaxSize;
    class MultiplyMaxSize³Command;
    class MultiplyMaxSizeˣCommand;
    class MultiplyMaxSizeʸCommand;
    class MultiplyMaxSizeᶻCommand;
    class SetMaxSize³Command;
    class SetMaxSizeˣCommand;
    class SetMaxSizeʸCommand;
    class SetMaxSizeᶻCommand;

    class AMaxSize³ : public IMaxSize³, public virtual Tachyon::Helper {
    public:
    
        //!  Basic max_size in the 3D space
        Size3D          max_size() const override { return m_max_size; }
        
        double          max_size(x_k) const { return m_max_size.x; }
        double          max_size(y_k) const { return m_max_size.y; }
        double          max_size(z_k) const { return m_max_size.z; }
        
        //!  SetMax max_size the max_size (OVERRIDE THIS TO INTERCEPT/REJECT)
        virtual void    max_size(set_k, const Size3D&) override;
        void            max_size(set_k, x_k, double) override;
        void            max_size(set_k, y_k, double) override;
        void            max_size(set_k, z_k, double) override;
        
        //!  Move the max_size (ie set to max_size + delta)
        void            max_size(add_k, const Vector3D&) override;
        void            max_size(add_k, x_k, double) override;
        void            max_size(add_k, y_k, double) override;
        void            max_size(add_k, z_k, double) override;

        void            max_size(multiply_k, double) override;
        void            max_size(multiply_k, const Vector3D&) override;
        void            max_size(multiply_k, x_k, double) override;
        void            max_size(multiply_k, y_k, double) override;
        void            max_size(multiply_k, z_k, double) override;
        
        bool            max_size(disabled_k) const { return false; }
        bool            max_size(settable_k) const { return true; }
        bool            max_size(addable_k) const { return true; }
        bool            max_size(multipliable_k) const { return true; }
        
        const Size3D&   max_size(ref_k) const { return m_max_size; }

    protected:

        Size3D      m_max_size = NAN;
        
        template <typename C>
        static void init_meta(TachyonMeta::Writer<C>&);
        
        AMaxSize³();
        virtual ~AMaxSize³();
        
        void        max_size(emit_k);
        
    private:
        void        on_set_max_size3(const SetMaxSize³Command&);
        void        on_set_max_sizeX(const SetMaxSizeˣCommand&);
        void        on_set_max_sizeY(const SetMaxSizeʸCommand&);
        void        on_set_max_sizeZ(const SetMaxSizeᶻCommand&);

        void        on_add_max_size3(const AddMaxSize³Command&);
        void        on_add_max_sizeX(const AddMaxSizeˣCommand&);
        void        on_add_max_sizeY(const AddMaxSizeʸCommand&);
        void        on_add_max_sizeZ(const AddMaxSizeᶻCommand&);
        
        void        on_multiply_max_size(const MultiplyMaxSize&);
        void        on_multiply_max_size3(const MultiplyMaxSize³Command&);
        void        on_multiply_max_sizeX(const MultiplyMaxSizeˣCommand&);
        void        on_multiply_max_sizeY(const MultiplyMaxSizeʸCommand&);
        void        on_multiply_max_sizeZ(const MultiplyMaxSizeᶻCommand&);

    };

}
