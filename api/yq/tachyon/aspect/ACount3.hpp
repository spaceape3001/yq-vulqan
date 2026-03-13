////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/interface/ICount3.hpp>
#include <yq/tachyon/api/Tachyon.hpp>

namespace yq::tachyon {

    class AddCount³UCommand;
    class AddCountˣUCommand;
    class AddCountʸUCommand;
    class AddCountᶻUCommand;
    class MultiplyCountUCommand; 
    class MultiplyCount³UCommand;
    class MultiplyCountˣUCommand;
    class MultiplyCountʸUCommand;
    class MultiplyCountᶻUCommand;
    class SetCount³UCommand;
    class SetCountˣUCommand;
    class SetCountʸUCommand;
    class SetCountᶻUCommand;

    class ACount³ : public ICount³, public virtual Tachyon::Helper {
    public:
    
        struct Param {
            Vector3U    count   = ONE;
        };
    
        //!  Basic count in the 3D space
        Vector3U        count() const override { return m_count; }

        unsigned          count(x_k) const { return m_count.x; }
        unsigned          count(y_k) const { return m_count.y; }
        unsigned          count(z_k) const { return m_count.z; }
        
        //!  Set count the count (OVERRIDE THIS TO INTERCEPT/REJECT)
        virtual void    count(set_k, const Vector3U&) override;
        void            count(set_k, x_k, unsigned) override;
        void            count(set_k, y_k, unsigned) override;
        void            count(set_k, z_k, unsigned) override;
        
        //!  Add the count (ie set to count + delta)
        void            count(add_k, const Vector3U&) override;
        void            count(add_k, x_k, unsigned) override;
        void            count(add_k, y_k, unsigned) override;
        void            count(add_k, z_k, unsigned) override;

        void            count(multiply_k, unsigned) override;
        void            count(multiply_k, const Vector3U&) override;
        void            count(multiply_k, x_k, unsigned) override;
        void            count(multiply_k, y_k, unsigned) override;
        void            count(multiply_k, z_k, unsigned) override;
        
        virtual bool    count(disabled_k) const override { return false; }
        virtual bool    count(settable_k) const override { return true; }
        virtual bool    count(addable_k) const override { return true; }
        virtual bool    count(multipliable_k) const override { return true; }

        const Vector3U& count(ref_k) const { return m_count; }

    protected:
        
        Vector3U    m_count;

        template <typename C>
        static void init_meta(TachyonMeta::Writer<C>&);
        
        ACount³(const Param&);
        ACount³(const Vector3U& cnt=ONE);
        virtual ~ACount³();
        
        void        count(emit_k);

    private:
        void        on_set_count3(const SetCount³UCommand&);
        void        on_set_countX(const SetCountˣUCommand&);
        void        on_set_countY(const SetCountʸUCommand&);
        void        on_set_countZ(const SetCountᶻUCommand&);

        void        on_add_count3(const AddCount³UCommand&);
        void        on_add_countX(const AddCountˣUCommand&);
        void        on_add_countY(const AddCountʸUCommand&);
        void        on_add_countZ(const AddCountᶻUCommand&);
        
        void        on_multiply_count(const MultiplyCountUCommand&);
        void        on_multiply_count3(const MultiplyCount³UCommand&);
        void        on_multiply_countX(const MultiplyCountˣUCommand&);
        void        on_multiply_countY(const MultiplyCountʸUCommand&);
        void        on_multiply_countZ(const MultiplyCountᶻUCommand&);
    };
}
