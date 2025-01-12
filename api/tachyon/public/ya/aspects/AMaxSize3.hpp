////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/interfaces/IMaxSize3.hpp>
#include <yt/api/Tachyon.hpp>

#ifdef NAN
#undef NAN
#endif

namespace yq::tachyon {

    class AddMaxSize³;
    class AddMaxSizeˣ;
    class AddMaxSizeʸ;
    class AddMaxSizeᶻ;
    class MultiplyMaxSize;
    class MultiplyMaxSize³;
    class MultiplyMaxSizeˣ;
    class MultiplyMaxSizeʸ;
    class MultiplyMaxSizeᶻ;
    class SetMaxSize³;
    class SetMaxSizeˣ;
    class SetMaxSizeʸ;
    class SetMaxSizeᶻ;

    class AMaxSize³ : public IMaxSize³, private Tachyon::Helper {
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
        static void init_info(TachyonInfo::Writer<C>&);
        
        AMaxSize³();
        virtual ~AMaxSize³();
        
        void        max_size(emit_k);
        
    private:
        void        on_set_max_size3(const SetMaxSize³&);
        void        on_set_max_sizeX(const SetMaxSizeˣ&);
        void        on_set_max_sizeY(const SetMaxSizeʸ&);
        void        on_set_max_sizeZ(const SetMaxSizeᶻ&);

        void        on_add_max_size3(const AddMaxSize³&);
        void        on_add_max_sizeX(const AddMaxSizeˣ&);
        void        on_add_max_sizeY(const AddMaxSizeʸ&);
        void        on_add_max_sizeZ(const AddMaxSizeᶻ&);
        
        void        on_multiply_max_size(const MultiplyMaxSize&);
        void        on_multiply_max_size3(const MultiplyMaxSize³&);
        void        on_multiply_max_sizeX(const MultiplyMaxSizeˣ&);
        void        on_multiply_max_sizeY(const MultiplyMaxSizeʸ&);
        void        on_multiply_max_sizeZ(const MultiplyMaxSizeᶻ&);

    };

}
