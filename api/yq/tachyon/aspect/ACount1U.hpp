////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/interface/ICount1U.hpp>
#include <yq/tachyon/api/Tachyon.hpp>

namespace yq::tachyon {

    class AddCount¹UCommand;
    class AddCountˣUCommand;
    class MultiplyCountUCommand;
    class MultiplyCount¹UCommand;
    class MultiplyCountˣUCommand;
    class SetCount¹UCommand;
    class SetCountˣUCommand;

    class ACount¹U : public ICount¹U, public virtual Tachyon::Helper {
    public:
    
        struct Param {
            Vector1U    count   = ONE;
        };
    
        //!  Basic count in the 1D space
        Vector1U        count() const override { return m_count; }

        unsigned          count(x_k) const { return m_count.x; }
        
        //!  Set count the count (OVERRIDE THIS TO INTERCEPT/REJECT)
        virtual void    count(set_k, const Vector1U&) override;
        void            count(set_k, x_k, unsigned) override;
        
        //!  Move the count (ie set to count + delta)
        void            count(add_k, const Vector1U&) override;
        void            count(add_k, x_k, unsigned) override;

        void            count(multiply_k, unsigned) override;
        void            count(multiply_k, const Vector1U&) override;
        void            count(multiply_k, x_k, unsigned) override;
        
        bool            count(disabled_k) const { return false; }
        bool            count(settable_k) const { return true; }
        bool            count(addable_k) const { return true; }
        bool            count(multipliable_k) const { return true; }

        const Vector1U& count(ref_k) const { return m_count; }

    protected:
        
        Vector1U    m_count;
        
        template <typename C>
        static void init_meta(TachyonMeta::Writer<C>&);
        
        ACount¹U(const Param&);
        ACount¹U(const Vector1U& cnt=ONE);
        virtual ~ACount¹U();

        void            count(emit_k);
        
    private:
        void        on_set_count1(const SetCount¹UCommand&);
        void        on_set_countX(const SetCountˣUCommand&);

        void        on_add_count1(const AddCount¹UCommand&);
        void        on_add_countX(const AddCountˣUCommand&);
        
        void        on_multiply_count(const MultiplyCountUCommand&);
        void        on_multiply_count1(const MultiplyCount¹UCommand&);
        void        on_multiply_countX(const MultiplyCountˣUCommand&);

    };

}
