class Solution:
    def dividePlayers(self, skill: List[int]) -> int:
        n = len(skill)
        total_skill = sum(skill)
        skill_frequency = [0] * 1001

        # Calculate total skill and skill frequency
        for player_skill in skill:
            skill_frequency[player_skill] += 1

        # Check if total skill can be evenly distributed among teams
        if total_skill % (n // 2) != 0:
            return -1

        target_team_skill = total_skill // (n // 2)
        total_chemistry = 0

        # Calculate total chemistry while verifying valid team formations
        for player_skill in skill:
            partner_skill = target_team_skill - player_skill

            # Check if a valid partner exists
            if skill_frequency[partner_skill] == 0:
                return -1

            # Calculate and add chemistry of the current pair
            total_chemistry += player_skill * partner_skill
            skill_frequency[partner_skill] -= 1

        # Return half of total_chemistry as each pair is counted twice
        return total_chemistry // 2
