////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/interfaces/ISize3.hpp>
#include <yt/api/Tachyon.hpp>

namespace yq::tachyon {

    class AddSize³;
    class AddSizeˣ;
    class AddSizeʸ;
    class AddSizeᶻ;
    class MultiplySize;
    class MultiplySize³;
    class MultiplySizeˣ;
    class MultiplySizeʸ;
    class MultiplySizeᶻ;
    class SetSize³;
    class SetSizeˣ;
    class SetSizeʸ;
    class SetSizeᶻ;

    class ASize³ : public ISize³, private Tachyon::Helper {
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

        Size3D      m_size = ONE;
        
        template <typename C>
        static void init_info(TachyonInfo::Writer<C>&);
        
        ASize³();
        virtual ~ASize³();
        
        void        size(emit_k);
        
    private:
        void        on_set_size3(const SetSize³&);
        void        on_set_sizeX(const SetSizeˣ&);
        void        on_set_sizeY(const SetSizeʸ&);
        void        on_set_sizeZ(const SetSizeᶻ&);

        void        on_add_size3(const AddSize³&);
        void        on_add_sizeX(const AddSizeˣ&);
        void        on_add_sizeY(const AddSizeʸ&);
        void        on_add_sizeZ(const AddSizeᶻ&);
        
        void        on_multiply_size(const MultiplySize&);
        void        on_multiply_size3(const MultiplySize³&);
        void        on_multiply_sizeX(const MultiplySizeˣ&);
        void        on_multiply_sizeY(const MultiplySizeʸ&);
        void        on_multiply_sizeZ(const MultiplySizeᶻ&);

    };

}
