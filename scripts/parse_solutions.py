#!/usr/bin/env python3
"""Parse solution files from solutions/ directory into data/problems.json."""
import json
import os
import re
from pathlib import Path

# Complete CSES problem categories mapping (all 300+ problems)
CATEGORIES = {
    "Introductory Problems": [
        1068, 1083, 1069, 1094, 1070, 1071, 1072, 1092, 1617, 1618,
        1754, 1755, 2205, 2165, 1622, 1623, 1624, 3399, 3419, 3217,
        3311, 2431, 1743, 1625,
    ],
    "Sorting and Searching": [
        1621, 1084, 1090, 1091, 1619, 1629, 1640, 1643, 1074, 2183,
        2216, 2217, 1141, 1073, 1163, 3420, 3421, 2162, 2163, 2168,
        2169, 1164, 1620, 1630, 1631, 1641, 1642, 1645, 1660, 1661,
        1662, 2428, 1085, 1632, 1644,
    ],
    "Dynamic Programming": [
        1633, 1634, 1635, 1636, 1637, 1638, 1158, 1746, 2413, 1639,
        3403, 1744, 3359, 1745, 1097, 1093, 3314, 1145, 1140, 1653,
        2181, 2220, 1748,
    ],
    "Graph Algorithms": [
        1192, 1193, 1666, 1667, 1668, 1669, 1194, 1671, 1672, 1673,
        1195, 1197, 1196, 1678, 1679, 1680, 1681, 1202, 1750, 1160,
        1751, 1675, 1676, 1682, 1683, 1684, 1686, 1691, 1692, 1693,
        1690, 1689, 1694, 1695, 1696, 1711,
    ],
    "Range Queries": [
        1646, 1647, 1648, 1649, 1650, 1651, 1652, 1143, 1749, 1144,
        2166, 2206, 3304, 3163, 1190, 3226, 1734, 3356, 2416, 1664,
        1739, 1735, 1736, 1737, 2184,
    ],
    "Tree Algorithms": [
        1674, 1130, 1131, 1132, 1133, 1687, 1688, 1135, 1136, 1137,
        1138, 2134, 1139, 2079, 2080, 2081,
    ],
    "Mathematics": [
        2164, 1095, 1712, 1713, 1081, 1082, 2182, 2185, 2417, 3396,
        1079, 1715, 1716, 1717, 3397, 3398, 2064, 2187, 2209, 2210,
        1722, 1096, 1723, 1724, 3154, 3355, 3406, 1725, 1726, 1727,
        1728, 1729, 1730, 1098, 1099, 2207, 2208,
    ],
    "String Algorithms": [
        1731, 1753, 1732, 1733, 1110, 1111, 3138, 1112, 2420, 2102,
        2103, 2104, 2105, 1149, 2106, 2107, 3225, 1113, 2108, 2109,
        2110,
    ],
    "Geometry": [
        2189, 2190, 2191, 2192, 2193, 2194, 2195, 3410, 3411, 1740,
        3427, 3428, 3429, 3430, 1741, 1742,
    ],
    "Advanced Techniques": [
        1628, 2136, 3360, 2137, 2138, 2143, 2072, 2073, 2074, 2076,
        2077, 2078, 2084, 2085, 2086, 2087, 2088, 2111, 2112, 2113,
        2101, 2133, 2121, 2129, 2130,
    ],
    "Sliding Window Problems": [
        3220, 3221, 3426, 3405, 3222, 3224, 3219, 1076, 1077, 3223,
        3227,
    ],
    "Interactive Problems": [
        3112, 3139, 3305, 3228, 3273, 3140,
    ],
    "Bitwise Operations": [
        1146, 1655, 3191, 3211, 3192, 3233, 2419, 3194, 3195, 1654,
        3141,
    ],
    "Construction Problems": [
        2214, 2215, 3422, 3423, 1697, 3424, 2423, 2418,
    ],
    "Advanced Graph Problems": [
        3303, 1134, 1702, 1757, 1756, 2177, 2179, 1707, 3357, 3111,
        3407, 3408, 3409, 1677, 3114, 3149, 1700, 1701, 1699, 1703,
        1203, 3308, 3158, 3358, 1704, 1705, 1752, 1685,
    ],
    "Counting Problems": [
        3413, 3414, 3415, 3416, 3417, 3418, 3400, 1080, 2229, 2176,
        2228, 1078, 1075, 2429, 2421, 3232, 3157, 2415,
    ],
    "Additional Problems I": [
        1087, 3150, 3190, 1670, 3175, 2422, 3151, 3152, 3306, 3307,
        1142, 2186, 3169, 3193, 3294, 3213, 3214, 2425, 3301, 3302,
        3361, 1747, 3404, 1188, 1086, 2427, 1147, 1162, 1191, 2414,
    ],
    "Additional Problems II": [
        3215, 3216, 3218, 3108, 3109, 2132, 1189, 1698, 2430, 1706,
        1709, 3312, 2426, 2174, 2180, 3159, 2432, 2131, 2115, 2075,
        1159, 3161, 3402, 3425, 1157, 1148, 1161, 3401, 1665, 2402,
    ],
}

# Build reverse mapping: problem_id -> category
ID_TO_CATEGORY = {}
for cat, ids in CATEGORIES.items():
    for pid in ids:
        ID_TO_CATEGORY[pid] = cat


def parse_filename(filename: str) -> dict | None:
    """Extract problem ID and name from filename like '1068-Weird_Algorithm.cpp'."""
    match = re.match(r"^(\d+)-(.+)\.(cpp|py)$", filename)
    if not match:
        return None
    problem_id = match.group(1)
    name = match.group(2).replace("_", " ")
    ext = match.group(3)
    return {
        "id": problem_id,
        "name": name,
        "extension": ext,
        "filename": filename,
    }


def main():
    base_dir = Path(__file__).parent.parent
    solutions_dir = base_dir / "solutions"
    data_dir = base_dir / "data"
    data_dir.mkdir(exist_ok=True)

    problems = []
    seen_ids = set()

    for filename in sorted(os.listdir(solutions_dir)):
        parsed = parse_filename(filename)
        if not parsed:
            continue

        # Skip duplicates (prefer .cpp over .py)
        if parsed["id"] in seen_ids:
            continue
        seen_ids.add(parsed["id"])

        # Read solution code
        solution_path = solutions_dir / filename
        code = solution_path.read_text()

        pid = int(parsed["id"])
        category = ID_TO_CATEGORY.get(pid, "Uncategorized")

        problems.append({
            "id": parsed["id"],
            "name": parsed["name"],
            "category": category,
            "csesUrl": f"https://cses.fi/problemset/task/{parsed['id']}",
            "solutionFile": filename,
            "solutionCode": code,
            "language": "cpp" if parsed["extension"] == "cpp" else "python",
        })

    # Sort by ID
    problems.sort(key=lambda p: int(p["id"]))

    output = {
        "generatedAt": None,  # Will be set by generate_editorials
        "totalProblems": len(problems),
        "problems": problems,
    }

    output_path = data_dir / "problems.json"
    with open(output_path, "w") as f:
        json.dump(output, f, indent=2)

    print(f"Parsed {len(problems)} problems into {output_path}")

    # Print category summary
    cat_counts = {}
    for p in problems:
        cat_counts[p["category"]] = cat_counts.get(p["category"], 0) + 1

    print("\nCategory breakdown:")
    for cat, count in sorted(cat_counts.items()):
        print(f"  {cat}: {count}")

    # Check for any uncategorized problems
    uncategorized = [p for p in problems if p["category"] == "Uncategorized"]
    if uncategorized:
        print(f"\nWarning: {len(uncategorized)} uncategorized problem(s):")
        for p in uncategorized:
            print(f"  {p['id']}: {p['name']}")


if __name__ == "__main__":
    main()
