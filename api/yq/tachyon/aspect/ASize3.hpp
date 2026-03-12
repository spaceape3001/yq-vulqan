////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/interface/ISize3.hpp>
#include <yq/tachyon/api/Tachyon.hpp>

namespace yq::tachyon {

    class AddSize³DCommand;
    class AddSizeˣDCommand;
    class AddSizeʸDCommand;
    class AddSizeᶻDCommand;
    class MultiplySizeDCommand;
    class MultiplySize³DCommand;
    class MultiplySizeˣDCommand;
    class MultiplySizeʸDCommand;
    class MultiplySizeᶻDCommand;
    class SetSize³DCommand;
    class SetSizeˣDCommand;
    class SetSizeʸDCommand;
    class SetSizeᶻDCommand;

    class ASize³ : public ISize³, public virtual Tachyon::Helper {
    public:
    
        static constexpr const Size3D   kDefSize    = ONE;

        struct Param {
            Size3D      size    = kDefSize;
        };
    
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

        Size3D      m_size;
        
        template <typename C>
        static void init_meta(TachyonMeta::Writer<C>&);
        
        ASize³(const Param&);
        ASize³(const Size3D& sz=kDefSize);
        virtual ~ASize³();
        
        void        size(emit_k);
        
    private:
        void        on_set_size3(const SetSize³DCommand&);
        void        on_set_sizeX(const SetSizeˣDCommand&);
        void        on_set_sizeY(const SetSizeʸDCommand&);
        void        on_set_sizeZ(const SetSizeᶻDCommand&);

        void        on_add_size3(const AddSize³DCommand&);
        void        on_add_sizeX(const AddSizeˣDCommand&);
        void        on_add_sizeY(const AddSizeʸDCommand&);
        void        on_add_sizeZ(const AddSizeᶻDCommand&);
        
        void        on_multiply_size(const MultiplySizeDCommand&);
        void        on_multiply_size3(const MultiplySize³DCommand&);
        void        on_multiply_sizeX(const MultiplySizeˣDCommand&);
        void        on_multiply_sizeY(const MultiplySizeʸDCommand&);
        void        on_multiply_sizeZ(const MultiplySizeᶻDCommand&);

    };

}
