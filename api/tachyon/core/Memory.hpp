////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once
#include <span>
#include <functional>
#include <type_traits>
#include <basic/keywords.hpp>

namespace yq::tachyon {
    /*! \brief Simple memory container
    
        Data can be allocated within here, or simply be a pointer 
        somewhere else.   Default "copy" uses new/delete.  "ref" 
        doesn't allocate/deallocate, but instead trusts the client
        to keep data valid for the duration of need.
    */
    class Memory {
    public:
        using Free = std::function<void(const void*, size_t)>;
        
        void        clear();
        bool        empty() const { return m_data == nullptr; }
        const void* data() const { return m_data; }
        size_t      size() const { return m_size; }
        
        /*! \brief Sets a COPY of the data

            This routine copies the data pointed to in the argument 
            into a separate buffer.
        */
        template <typename T>
        void    copy(const T*, size_t);

        /*! \brief Sets a COPY of the data
        
            This routine copies the data pointed to in the argument 
            into a separate buffer.
        */
        template <typename T>
        void    copy(std::span<const T>);


        /*! \brief Sets a COPY of the data

            This routine copies the data pointed to in the argument 
            into a separate buffer.
        */
        template <typename T, size_t N>
        void    copy(const T (&ptr)[N]);

        /*! \brief Sets a COPY of the data

            This routine copies the data pointed to in the argument 
            into a separate buffer.
        */
        template <typename T>
        void    copy(const T&);
        
        /*! \brief Sets a REFERENCE to the data
        
            This routine creates a REFERENCE to the data in the argument,
            and this data MUST remain valid for the duration of the usage.
        */
        template <typename T>
        void    ref(const T*, size_t); 

        /*! \brief Sets a REFERENCE to the data

            This routine creates a REFERENCE to the data in the argument,
            and this data MUST remain valid for the duration of the usage.
        */
        template <typename T>
        void    ref(std::span<const T>); 

        /*! \brief Sets a REFERENCE to the data

            This routine creates a REFERENCE to the data in the argument,
            and this data MUST remain valid for the duration of the usage.
        */
        template <typename T, size_t N>
        void    ref(const T (&ptr)[N]);

        /*! \brief Sets a REFERENCE to the data

            This routine creates a REFERENCE to the data in the argument,
            and this data MUST remain valid for the duration of the usage.
        */
        template <typename T>
        void    ref(const T&);

        template <typename T>
        void    ref(T&&) = delete;

        void    set(const void*, size_t, Free free={}); 

        template <typename ... Args>
        Memory(copy_t, Args...args) : Memory()
        {
            copy(args...);
        }

        template <typename ... Args>
        Memory(ref_t, Args...args) : Memory()
        {
            ref(args...);
        }

        Memory(const void*, size_t, Free free={});
        
        Memory();
        Memory(Memory&& mv);
        Memory& operator=(Memory&&);
        ~Memory();
        
    private:
    
        Memory(const Memory&) = delete;
        Memory& operator=(const Memory&) = delete;
    
        const void*     m_data  = nullptr;
        size_t          m_size  = 0ULL;
        Free            m_free  = {};
    };

    template <typename T>
    void    Memory::copy(const T*p, size_t n)
    {
        static_assert(std::is_trivially_copyable_v<T>, "Can only set with trivial types!");
        if(!p || !n)
            return ;
            
        T*    ndata   = new T[n];
        std::copy(p, p+n, ndata);
        set(ndata, n * sizeof(T), [](const void* p2, size_t sz) {
            delete[] ((const T*) p2);
        });
    }

    template <typename T>
    void    Memory::copy(std::span<const T> d)
    {
        copy(d.data(), d.size());
    }

    template <typename T, size_t N>
    void    Memory::copy(const T (&ptr)[N])
    {
        copy(ptr, N);
    }
    

    template <typename T>
    void    Memory::copy(const T&v)
    {
        static_assert(std::is_trivially_copyable_v<T>, "Can only set with trivial types!");
        set( new T(v), sizeof(T), [](const void*p, size_t){
            delete ((const T*) p);
        });
    }
    
    template <typename T>
    void    Memory::ref(const T* p, size_t cnt)
    {
        static_assert(std::is_trivially_copyable_v<T>, "Can only set with trivial types!");
        set(p, cnt*sizeof(T));
    }

    template <typename T>
    void    Memory::ref(std::span<const T>sp)
    {
        ref(sp.data(), sp.size());
    }

    template <typename T, size_t N>
    void    Memory::ref(const T (&ptr)[N])
    {
        ref(ptr, N);
    }

    template <typename T>
    void    Memory::ref(const T& p)
    {
        static_assert(std::is_trivially_copyable_v<T>, "Can only set with trivial types!");
        set(&p, sizeof(T));
    }

};

