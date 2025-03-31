////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

namespace yq::tachyon {
    class LayoutItem⁴ : public IPosition⁴, public IMaxSize⁴, public IMinSize⁴, public ISize⁴, public virtual Tachyon::Helper {
    public:
    
    private:
        enum class F : uint8_t {
            AddMaxSize,
            AddMinSize,
            AddPosition,
            AddSize,
            
            EnableMaxSize,
            EnableMinSize,
            EnablePosition,
            EnableSize,
            
            MultiplyMaxSize,
            MultiplyMinSize,
            MultiplyPosition,
            MultiplySize,
            
            SetMaxSize,
            SetMinSize,
            SetPosition,
            SetSize
        };
        
        Size4D              m_size, m_min, m_max, m_hint;
        Vector4D            m_position;
        Flags<F,uint128_t>  m_flags;
        SizePolicy4         m_policy;
    };
}
