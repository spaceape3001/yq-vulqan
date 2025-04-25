////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/SizeCommand.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {

    //! Instructs an object to multiply it's scale
    class MultiplyMaxSize³ : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplyMaxSize³, SizeCommand)
    public:
        MultiplyMaxSize³(const Header&, const Vector3D&);
    
        const Vector3D&   δ() const  { return m_δ; }
        
        static void init_info();
        
        double  δx() const { return m_δ.x; }
        double  δy() const { return m_δ.y; }
        double  δz() const { return m_δ.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyMaxSize³(const MultiplyMaxSize³&, const Header&);
        MultiplyMaxSize³(const Header&);
        ~MultiplyMaxSize³();

    private:
        Vector3D  m_δ;
        
        MultiplyMaxSize³(const MultiplyMaxSize³&) = delete;
        MultiplyMaxSize³(MultiplyMaxSize³&&) = delete;
        MultiplyMaxSize³& operator=(const MultiplyMaxSize³&) = delete;
        MultiplyMaxSize³& operator=(MultiplyMaxSize³&&) = delete;
    };
}
