template<typename T>
std::list<T> sequential_quick_sort(std::list<T> input)
{
    if(input.empty())
    {
        return input;
    }
    std::list<T> result;
    result.splice(result.begin(),input,input.begin()); //1
    T const& pivot=*result.begin(); //  2
    auto divide_point=std::partition(input.begin(),input.end(),
        [&](T const& t){return t<pivot;}); // 3
    std::list<T> lower_part;
    lower_part.splice(lower_part.end(),input,input.begin(),
        divide_point); // 4
    auto new_lower(
        sequential_quick_sort(std::move(lower_part)));
    auto new_higher(
        sequential_quick_sort(std::move(input))); // 6
    result.splice(result.end(),new_higher); // 7
    //Using synchronization of operations to simplify code
        result.splice(result.begin(),new_lower); // 8
    return result;
}
