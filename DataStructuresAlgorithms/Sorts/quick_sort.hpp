/**
 * Daniel Sebastian Iliescu
 *
 * An implementation of quick sort.
 */

#pragma once

#include "sort.hpp"

namespace dsa
{
    template < typename T >
    void quicksort( T* data, const std::size_t size )
    {
        if ( ( data != nullptr ) &&
             ( size >= 0 ) )
        {
            quicksort( data, 0, size - 1 );
        }
    }

    template < typename T >
    void quicksort( T* data, const std::size_t low, const std::size_t high )
    {
        if ( low < high )
        {
            const std::size_t mid = ( low + high ) / 2;
            std::size_t pivot = partition( data, low, high, mid );

            quicksort( data, low, pivot );
            quicksort( data, pivot + 1, high );
        }
    }
}
