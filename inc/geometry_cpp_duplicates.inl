#include "geometry_cpp.hpp"
#include "geometry_cpp_algorithm.hpp"


namespace geometry_cpp
{
   namespace algorithm
   {
      template <typename T>
      struct remove_duplicates
      {
      public:

         template <typename InputIterator, typename OutputIterator>
         remove_duplicates(InputIterator begin, InputIterator end, OutputIterator out)
         {
            std::sort(begin,end);

            T previous = (*begin);
              (*out++) = (*begin);

            for (InputIterator it = (begin + 1); it != end; ++it)
            {
               if ((*it) > previous)
               {
                  (*out++) = (*it);
                  previous = (*it);
               }
            }
         }
      };

   } // namespace geometry_cpp::algorithm

} // namespace geometry_cpp
