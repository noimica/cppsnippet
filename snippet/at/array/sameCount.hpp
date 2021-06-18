// 重複した要素をカウント
// O(N)
template <class Iterator>
umap<typename iterator_traits<Iterator>::value_type, ll>
sameCount(const Iterator begin, const Iterator end){
    umap<typename iterator_traits<Iterator>::value_type, ll> mp;
    for (auto it = begin; it != end; ++it) ++mp[*it];
    return mp;
}