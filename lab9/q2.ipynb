from pgmpy.models import DiscreteBayesianNetwork
from pgmpy.factors.discrete import TabularCPD
from pgmpy.inference import VariableElimination

model = DiscreteBayesianNetwork([
    ('Intelligence', 'Grade'),
    ('StudyHours', 'Grade'),
    ('Difficulty', 'Grade'),
    ('Grade', 'Pass')
])

cpd_i = TabularCPD('Intelligence', 2, [[0.3], [0.7]])
cpd_s = TabularCPD('StudyHours', 2, [[0.4], [0.6]])
cpd_d = TabularCPD('Difficulty', 2, [[0.4], [0.6]])

cpd_g = TabularCPD(
    variable='Grade', variable_card=3,
    values=[
        [0.05, 0.10, 0.15, 0.20, 0.25, 0.35, 0.40, 0.50],
        [0.25, 0.30, 0.35, 0.40, 0.45, 0.40, 0.40, 0.35],
        [0.70, 0.60, 0.50, 0.40, 0.30, 0.25, 0.20, 0.15]
    ],
    evidence=['Intelligence', 'StudyHours', 'Difficulty'],
    evidence_card=[2, 2, 2]
)

cpd_p = TabularCPD(
    variable='Pass', variable_card=2,
    values=[
        [0.05, 0.20, 0.50],
        [0.95, 0.80, 0.50]
    ],
    evidence=['Grade'],
    evidence_card=[3]
)

model.add_cpds(cpd_i, cpd_s, cpd_d, cpd_g, cpd_p)
assert model.check_model()

infer = VariableElimination(model)

r1 = infer.query(['Pass'], evidence={'StudyHours': 1, 'Difficulty': 0})
print("\n=== Task 2 ===")
print("P(Pass | StudyHours=Sufficient, Difficulty=Hard):")
print(r1)

r2 = infer.query(['Intelligence'], evidence={'Pass': 1})
print("P(Intelligence | Pass=Yes):")
print(r2)
