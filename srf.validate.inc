<?php

/**
 * Helper function to clean customized field label,
 * to print it in an error message
 * @param  string $srf_label Label to be cleaned
 */
function srf_clean_field_label($srf_label) {
  return str_replace(' *', '', strip_tags($srf_label));
}

/**
 * Helper function to print publication warning on a field.
 * @param  string $field_name  Field machine name
 * @param  string $field_label Field (instance) label
 */
function srf_print_field_warning($field_name, $field_label, $new_status) {
  form_set_error($field_name, t('Field <strong>@field_label</strong> is required to pass this content as: <strong>@new_status</strong>.',
    array('@field_label' => $field_label, '@new_status' => $new_status)));
}

/**
 * Helper function to check filling text_long fields.
 */
function srf_text_long_validate($element, &$form_state, $form, $new_status) {
  $field_name = $element['#field_name'];
  $field_language = field_language($form['#entity_type'], $form_state['node'], $field_name);
  $field_values = $form_state['values'][$field_name][$field_language];
  if (!$field_values[0]['value']) {
    $field_label = srf_clean_field_label($element['#title']);
    srf_print_field_warning($field_name, $field_label, $new_status);
  }
}

/**
 * Helper function to check filling text_with_summary fields.
 */
function srf_text_with_summary_validate($element, &$form_state, $form, $new_status) {
  $field_name = $element['#field_name'];
  $field_language = field_language($form['#entity_type'], $form_state['node'], $field_name);
  $field_values = $form_state['values'][$field_name][$field_language];
  if (!$field_values[0]['value']) {
    $field_label = srf_clean_field_label($element['#title']);
    srf_print_field_warning($field_name, $field_label, $new_status);
  }

}

/**
 * Helper function to check filling entityreference fields.
 */
function srf_entityreference_validate($element, &$form_state, $form, $new_status) {
  $field_name = $element['target_id']['#field_name'];
  $field_language = field_language($form['#entity_type'], $form_state['node'], $field_name);
  $field_values = $form_state['values'][$field_name][$field_language];
  if (!$field_values[0]['target_id']) {
    $field_label = srf_clean_field_label($element['target_id']['#title']);
    srf_print_field_warning($field_name, $field_label, $new_status);
  }
}

/**
 * Helper function to check filling taxonomy_term_reference fields.
 */
function srf_taxonomy_term_reference_validate($element, &$form_state, $form, $new_status) {
  $field_name = $element['#field_name'];
  $field_language = field_language($form['#entity_type'], $form_state['node'], $field_name);
  $field_values = $form_state['values'][$field_name][$field_language];
  if (empty($field_values)) {
    $field_label = srf_clean_field_label($element['#title']);
    srf_print_field_warning($field_name, $field_label, $new_status);
  }
}

/**
 * Helper function to check filling image fields.
 */
function srf_image_validate($element, &$form_state, $form, $new_status) {
  foreach ($element as $id => &$elem) {
    $field_name = $elem['#field_name'];
    $field_language = field_language($form['#entity_type'], $form_state['node'], $field_name);
    $field_values = $form_state['values'][$field_name][$field_language];
    if (!$field_values[0]['fid']) {
      $field_label = srf_clean_field_label($elem['#title']);
      srf_print_field_warning($field_name, $field_label, $new_status);
    }
  }
}
